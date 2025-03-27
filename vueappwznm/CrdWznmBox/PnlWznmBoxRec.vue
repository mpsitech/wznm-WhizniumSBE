<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="9">
					<div class="caption text-decoration-underline">{{tag.Cpt}}</div>
					<div>{{continf.TxtRef}}</div>
				</v-col>
				<v-col cols="3" align="end">
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeCLick')"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						:disabled="!statshr.ButRegularizeActive"
						v-on:click="handleButClick('ButRegularizeClick')"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWznmVExpstate=='regd'"
		>
			<v-row>
				<v-col cols="12" md="12">
					<PnlWznmBoxDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmBoxDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmBoxOrgMNBox
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmBoxOrgMNBox"
						:scrJref=statshr.scrJrefOrgMNBox
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmBoxDstMNBox
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmBoxDstMNBox"
						:scrJref=statshr.scrJrefDstMNBox
					/>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	*/
	import PnlWznmBoxDetail from './PnlWznmBoxDetail';
	import PnlWznmBoxOrgMNBox from './PnlWznmBoxOrgMNBox';
	import PnlWznmBoxDstMNBox from './PnlWznmBoxDstMNBox';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmBoxRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmBoxDetail,
			PnlWznmBoxOrgMNBox,
			PnlWznmBoxDstMNBox
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmBoxRec.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmBoxRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmBoxRec) this.continf = dpcheng.ContInfWznmBoxRec;
				if (dpcheng.StatAppWznmBoxRec) this.statapp = dpcheng.StatAppWznmBoxRec;
				if (dpcheng.StatShrWznmBoxRec) this.statshr = dpcheng.StatShrWznmBoxRec;
				if (dpcheng.TagWznmBoxRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmBoxRec);
					this.tag = dpcheng.TagWznmBoxRec;
				}
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				//console.log(obj);
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
					else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						/*
						*/
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmBoxDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefOrgMNBox) this.$refs.PnlWznmBoxOrgMNBox.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefDstMNBox) this.$refs.PnlWznmBoxDstMNBox.handleReply(obj);
						/*
						*/
					}
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngWznmBoxRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmBoxRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmBoxDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefOrgMNBox) this.$refs.PnlWznmBoxOrgMNBox.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefDstMNBox) this.$refs.PnlWznmBoxDstMNBox.handleUpdate(obj);
						/*
						*/
						else processed = false;
					}
				}

				return processed
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
