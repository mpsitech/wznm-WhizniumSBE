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
				v-model="contapp.fiFDetPupTrg"
				:items="feedFDetPupTrg"
				:label='tag.CptDetTrg'
				v-on:change="handlePupChange('numFDetPupTrg', contapp.fiFDetPupTrg)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

			<v-select
				class="my-1"
				v-model="contapp.fiFDetPupVer"
				:items="feedFDetPupVer"
				:label='tag.CptDetVer'
				v-on:change="handlePupChange('numFDetPupVer', contapp.fiFDetPupVer)"
			>
				<template v-slot:selection="{item}">{{item.tit1}}</template>
				<template v-slot:item="{item}">{{item.tit1}}</template>
			</v-select>

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
		name: 'DlgWznmAppNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmAppNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmAppNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmAppNewDo"]["srefIxVDo" + ditshort] = ctlsref;

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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmAppNew"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmAppNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmAppNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmAppNew) this.contiac = dpcheng.ContIacDlgWznmAppNew;
				if (dpcheng.ContInfDlgWznmAppNew) this.continf = dpcheng.ContInfDlgWznmAppNew;
				if (dpcheng.FeedFDetPupTrg) this.feedFDetPupTrg = dpcheng.FeedFDetPupTrg;
				if (dpcheng.FeedFDetPupVer) this.feedFDetPupVer = dpcheng.FeedFDetPupVer;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmAppNew) this.statapp = dpcheng.StatAppDlgWznmAppNew;
				if (dpcheng.StatShrDlgWznmAppNew) this.statshr = dpcheng.StatShrDlgWznmAppNew;
				if (dpcheng.TagDlgWznmAppNew) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppNew);
					this.tag = dpcheng.TagDlgWznmAppNew;
				}
				if (dpcheng.ContIacDlgWznmAppNew) {
					for (let i = 0; i < this.feedFDetPupTrg.length; i++)
						if (this.feedFDetPupTrg[i].num == this.contiac.numFDetPupTrg) {
							this.contapp.fiFDetPupTrg = this.feedFDetPupTrg[i];
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmAppNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmAppNewData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDetPupTrg: null,

			feedFDetPupVer: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,

			contapp: {
				fiFDetPupTrg: null,

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
