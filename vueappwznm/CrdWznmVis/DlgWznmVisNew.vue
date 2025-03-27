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
				v-model="contapp.fiFDetPupTyp"
				return-object
				:items="feedFDetPupTyp"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetTyp"
				v-on:change="handleFiChange('', 'numFDetPupTyp', contapp.fiFDetPupTyp)"
			/>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupVer"
				return-object
				:items="feedFDetPupVer"
				item-value="num"
				item-text="tit1"
				:label="tag.CptDetVer"
				v-on:change="handleFiChange('', 'numFDetPupVer', contapp.fiFDetPupVer)"
			/>

			<v-text-field
				class="my-1"
				v-model="contiac.DetTxfCmt"
				:label="tag.CptDetCmt"
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

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgWznmVisNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVisNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVisNewDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVisNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVisNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVisNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVisNew) this.contiac = dpcheng.ContIacDlgWznmVisNew;
				if (dpcheng.ContInfDlgWznmVisNew) this.continf = dpcheng.ContInfDlgWznmVisNew;
				if (dpcheng.FeedFDetPupTyp) this.feedFDetPupTyp = dpcheng.FeedFDetPupTyp;
				if (dpcheng.FeedFDetPupVer) this.feedFDetPupVer = dpcheng.FeedFDetPupVer;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVisNew) this.statapp = dpcheng.StatAppDlgWznmVisNew;
				if (dpcheng.StatShrDlgWznmVisNew) this.statshr = dpcheng.StatShrDlgWznmVisNew;
				if (dpcheng.TagDlgWznmVisNew) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisNew);
					this.tag = dpcheng.TagDlgWznmVisNew;
				}
				if (dpcheng.ContIacDlgWznmVisNew) {
					for (let i = 0; i < this.feedFDetPupTyp.length; i++)
						if (this.feedFDetPupTyp[i].num == this.contiac.numFDetPupTyp) {
							this.contapp.fiFDetPupTyp = this.feedFDetPupTyp[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupVer.length; i++)
						if (this.feedFDetPupVer[i].num == this.contiac.numFDetPupVer) {
							this.contapp.fiFDetPupVer = this.feedFDetPupVer[i];
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVisNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVisNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetPupTyp: null,

			feedFDetPupVer: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupTyp: null,

				fiFDetPupVer: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
