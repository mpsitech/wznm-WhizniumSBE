<template>
	<v-card v-if="initdone" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{tag.Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end"/>
			</v-row>
		</v-card-title>
		<v-card-text>
			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfSho"
				:label="tag.CptDetSho"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfTit"
				:label="tag.CptDetTit"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfAbt"
				:label="tag.CptDetAbt"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fisFDetLstDty"
				multiple
				return-object
				:items="feedFDetLstDty"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetDty"
				v-on:change="handleFisChange('', 'numsFDetLstDty', contapp.fisFDetLstDty)"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fisFDetLstLoc"
				multiple
				return-object
				:items="feedFDetLstLoc"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetLoc"
				v-on:change="handleFisChange('', 'numsFDetLstLoc', contapp.fisFDetLstLoc)"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupPlc"
				return-object
				:items="feedFDetPupPlc"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetPlc"
				v-on:change="handleFiChange('', 'numFDetPupPlc', contapp.fiFDetPupPlc)"
			/>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupPmc"
				return-object
				:items="feedFDetPupPmc"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetPmc"
				v-on:change="handleFiChange('', 'numFDetPupPmc', contapp.fiFDetPupPmc)"
			/>

			<v-divider/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('', 'DetButAutClick')"
						:disabled="!statshr.DetButAutActive"
						class="my-1"
						color="primary"
					>
						{{tag.DetButAut}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCncClick')"
			>
				{{tag.ButCnc}}
			</v-btn>
			&#160;
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButCreClick')"
			>
				{{tag.ButCre}}
			</v-btn>
		</v-card-actions>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';
	import vecio from '../../scripts/vecio';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgWznmPrjNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmPrjNew.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ditshort, ctlsref) {
				var srefIxVDo = "srefIxVDo";
				if (ditshort != "") srefIxVDo += ditshort.charAt(0).toUpperCase() + ditshort.slice(1);

				const dpchapp = {
					"DpchAppDlgWznmPrjNewDo": {
						"scrJref": this.scrJref,
						[srefIxVDo]: ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleFiChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			handleFisChange: function(cisref, fis) {
				var nums = new Uint32Array(fis.length);

				for (let i = 0; i < fis.length; i++) nums[i] = fis[i].num;
				this["contiac" + ditshort][cisref] = vecio.toBase64(nums);

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmPrjNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmPrjNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmPrjNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmPrjNew) this.contiac = dpcheng.ContIacDlgWznmPrjNew;
				if (dpcheng.ContInfDlgWznmPrjNew) this.continf = dpcheng.ContInfDlgWznmPrjNew;
				if (dpcheng.FeedFDetLstDty) this.feedFDetLstDty = dpcheng.FeedFDetLstDty;
				if (dpcheng.FeedFDetLstLoc) this.feedFDetLstLoc = dpcheng.FeedFDetLstLoc;
				if (dpcheng.FeedFDetPupPlc) this.feedFDetPupPlc = dpcheng.FeedFDetPupPlc;
				if (dpcheng.FeedFDetPupPmc) this.feedFDetPupPmc = dpcheng.FeedFDetPupPmc;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmPrjNew) this.statapp = dpcheng.StatAppDlgWznmPrjNew;
				if (dpcheng.StatShrDlgWznmPrjNew) this.statshr = dpcheng.StatShrDlgWznmPrjNew;
				if (dpcheng.TagDlgWznmPrjNew) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmPrjNew);
					this.tag = dpcheng.TagDlgWznmPrjNew;
				}
				if (dpcheng.ContIacDlgWznmPrjNew) {
					var fisFDetLstDty = [];
					var numsFDetLstDty = vecio.parseUintvec(this.contiac.numsFDetLstDty);

					for (let i = 0; i < this.feedFDetLstDty.length; i++)
						if (numsFDetLstDty.includes(this.feedFDetLstDty[i].num))
							fisFDetLstDty.push(this.feedFDetLstDty[i]);

					this.contapp.fisFDetLstDty = fisFDetLstDty;
					var fisFDetLstLoc = [];
					var numsFDetLstLoc = vecio.parseUintvec(this.contiac.numsFDetLstLoc);

					for (let i = 0; i < this.feedFDetLstLoc.length; i++)
						if (numsFDetLstLoc.includes(this.feedFDetLstLoc[i].num))
							fisFDetLstLoc.push(this.feedFDetLstLoc[i]);

					this.contapp.fisFDetLstLoc = fisFDetLstLoc;
					for (let i = 0; i < this.feedFDetPupPlc.length; i++)
						if (this.feedFDetPupPlc[i].num == this.contiac.numFDetPupPlc) {
							this.contapp.fiFDetPupPlc = this.feedFDetPupPlc[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupPmc.length; i++)
						if (this.feedFDetPupPmc[i].num == this.contiac.numFDetPupPmc) {
							this.contapp.fiFDetPupPmc = this.feedFDetPupPmc[i];
							break;
						}
				}
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngDlgWznmPrjNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmPrjNewData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFDetLstDty: null,

			feedFDetLstLoc: null,

			feedFDetPupPlc: null,

			feedFDetPupPmc: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fisFDetLstDty: [],

				fisFDetLstLoc: [],

				fiFDetPupPlc: null,

				fiFDetPupPmc: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
