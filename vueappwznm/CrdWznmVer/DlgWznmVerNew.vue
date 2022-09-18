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
			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupPrj"
				return-object
				:items="feedFDetPupPrj"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetPrj"
				v-on:change="handleFiChange('', 'numFDetPupPrj', contapp.fiFDetPupPrj)"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupBvr"
				return-object
				:items="feedFDetPupBvr"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetBvr"
				v-on:change="handleFiChange('', 'numFDetPupBvr', contapp.fiFDetPupBvr)"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfCmt"
				:label="tag.CptDetCmt"
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
		name: 'DlgWznmVerNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVerNewDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVerNew) this.contiac = dpcheng.ContIacDlgWznmVerNew;
				if (dpcheng.ContInfDlgWznmVerNew) this.continf = dpcheng.ContInfDlgWznmVerNew;
				if (dpcheng.FeedFDetLstLoc) this.feedFDetLstLoc = dpcheng.FeedFDetLstLoc;
				if (dpcheng.FeedFDetPupBvr) this.feedFDetPupBvr = dpcheng.FeedFDetPupBvr;
				if (dpcheng.FeedFDetPupPlc) this.feedFDetPupPlc = dpcheng.FeedFDetPupPlc;
				if (dpcheng.FeedFDetPupPrj) this.feedFDetPupPrj = dpcheng.FeedFDetPupPrj;
				if (dpcheng.FeedFDetRbuVni) this.feedFDetRbuVni = dpcheng.FeedFDetRbuVni;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerNew) this.statapp = dpcheng.StatAppDlgWznmVerNew;
				if (dpcheng.StatShrDlgWznmVerNew) this.statshr = dpcheng.StatShrDlgWznmVerNew;
				if (dpcheng.TagDlgWznmVerNew) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerNew);
					this.tag = dpcheng.TagDlgWznmVerNew;
				}
				if (dpcheng.ContIacDlgWznmVerNew) {
					for (let i = 0; i < this.feedFDetPupPrj.length; i++)
						if (this.feedFDetPupPrj[i].num == this.contiac.numFDetPupPrj) {
							this.contapp.fiFDetPupPrj = this.feedFDetPupPrj[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupBvr.length; i++)
						if (this.feedFDetPupBvr[i].num == this.contiac.numFDetPupBvr) {
							this.contapp.fiFDetPupBvr = this.feedFDetPupBvr[i];
							break;
						}
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetLstLoc: null,

			feedFDetPupBvr: null,

			feedFDetPupPlc: null,

			feedFDetPupPrj: null,

			feedFDetRbuVni: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupPrj: null,

				fiFDetPupBvr: null,

				fisFDetLstLoc: [],

				fiFDetPupPlc: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
