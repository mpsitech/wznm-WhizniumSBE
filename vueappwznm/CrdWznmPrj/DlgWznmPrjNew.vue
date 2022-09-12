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

			<div
				class="my-1"
			>
				<!-- IP divDetDty - INSERT -->
			</div>

			<v-divider/>

			<div
				class="my-1"
			>
				<!-- IP divDetLoc - INSERT -->
			</div>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupPlc"
				:items="feedFDetPupPlc"
				:label='tag.CptDetPlc'
				v-on:change="handlePupChange('numFDetPupPlc', contapp.fiFDetPupPlc)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupPmc"
				:items="feedFDetPupPmc"
				:label='tag.CptDetPmc'
				v-on:change="handlePupChange('numFDetPupPmc', contapp.fiFDetPupPmc)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-divider/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('DetButAutClick')"
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
				var dpchapp = {
					"DpchAppDlgWznmPrjNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmPrjNewDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

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
