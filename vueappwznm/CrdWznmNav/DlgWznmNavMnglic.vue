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
			<h3
				class="text-5 my-1"
			>
				{{tag.DetHdgSrv}}
			</h3>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtSip"
				:label="tag.CptDetSip"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtScp"
				:label="tag.CptDetScp"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('', 'DetButScnClick')"
						class="my-1"
						color="primary"
					>
						{{tag.DetButScn}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('', 'DetButSdcClick')"
						class="my-1"
						color="primary"
					>
						{{tag.DetButSdc}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupFis"
				return-object
				:items="feedFDetPupFis"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetFis"
				v-on:change="handleFiChange('', 'numFDetPupFis', contapp.fiFDetPupFis)"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetLstLcs"
				return-object
				:items="feedFDetLstLcs"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetLcs"
				v-on:change="handleFiChange('', 'numFDetLstLcs', contapp.fiFDetLstLcs)"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('', 'DetButActClick')"
						:disabled="!statshr.DetButActActive"
						class="my-1"
						color="primary"
					>
						{{tag.DetButAct}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<h3
				class="text-5 my-1"
			>
				{{tag.DetHdgLic}}
			</h3>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLsr"
				:label="tag.CptDetLsr"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLar"
				:label="tag.CptDetLar"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLst"
				:label="tag.CptDetLst"
			/>

			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.DetTxtLex"
				:label="tag.CptDetLex"
			/>

		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButDneClick')"
			>
				{{tag.ButDne}}
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
		name: 'DlgWznmNavMnglic',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmNavMnglic.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmNavMnglicDo": {
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

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmNavMnglic"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmNavMnglicData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmNavMnglicData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmNavMnglic) this.contiac = dpcheng.ContIacDlgWznmNavMnglic;
				if (dpcheng.ContInfDlgWznmNavMnglic) this.continf = dpcheng.ContInfDlgWznmNavMnglic;
				if (dpcheng.FeedFDetLstLcs) this.feedFDetLstLcs = dpcheng.FeedFDetLstLcs;
				if (dpcheng.FeedFDetPupFis) this.feedFDetPupFis = dpcheng.FeedFDetPupFis;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmNavMnglic) this.statapp = dpcheng.StatAppDlgWznmNavMnglic;
				if (dpcheng.StatShrDlgWznmNavMnglic) this.statshr = dpcheng.StatShrDlgWznmNavMnglic;
				if (dpcheng.TagDlgWznmNavMnglic) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmNavMnglic);
					this.tag = dpcheng.TagDlgWznmNavMnglic;
				}
				if (dpcheng.ContIacDlgWznmNavMnglic) {
					for (let i = 0; i < this.feedFDetPupFis.length; i++)
						if (this.feedFDetPupFis[i].num == this.contiac.numFDetPupFis) {
							this.contapp.fiFDetPupFis = this.feedFDetPupFis[i];
							break;
						}
					for (let i = 0; i < this.feedFDetLstLcs.length; i++)
						if (this.feedFDetLstLcs[i].num == this.contiac.numFDetLstLcs) {
							this.contapp.fiFDetLstLcs = this.feedFDetLstLcs[i];
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmNavMnglicData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmNavMnglicData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetLstLcs: null,

			feedFDetPupFis: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupFis: null,

				fiFDetLstLcs: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
