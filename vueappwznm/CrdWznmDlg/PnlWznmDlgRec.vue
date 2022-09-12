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
					<PnlWznmDlgDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmDlgDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmDlgHk1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmDlgHk1NControl"
						:scrJref=statshr.scrJrefHk1NControl
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmDlgRef1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmDlgRef1NControl"
						:scrJref=statshr.scrJrefRef1NControl
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmDlgMNQuery
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmDlgMNQuery"
						:scrJref=statshr.scrJrefMNQuery
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
	import PnlWznmDlgDetail from './PnlWznmDlgDetail';
	import PnlWznmDlgHk1NControl from './PnlWznmDlgHk1NControl';
	import PnlWznmDlgRef1NControl from './PnlWznmDlgRef1NControl';
	import PnlWznmDlgMNQuery from './PnlWznmDlgMNQuery';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmDlgRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmDlgDetail,
			PnlWznmDlgHk1NControl,
			PnlWznmDlgRef1NControl,
			PnlWznmDlgMNQuery
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmDlgRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmDlgRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmDlgRec) this.continf = dpcheng.ContInfWznmDlgRec;
				if (dpcheng.StatAppWznmDlgRec) this.statapp = dpcheng.StatAppWznmDlgRec;
				if (dpcheng.StatShrWznmDlgRec) this.statshr = dpcheng.StatShrWznmDlgRec;
				if (dpcheng.TagWznmDlgRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmDlgRec);
					this.tag = dpcheng.TagWznmDlgRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmDlgDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NControl) this.$refs.PnlWznmDlgHk1NControl.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NControl) this.$refs.PnlWznmDlgRef1NControl.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNQuery) this.$refs.PnlWznmDlgMNQuery.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmDlgRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmDlgRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmDlgDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NControl) this.$refs.PnlWznmDlgHk1NControl.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NControl) this.$refs.PnlWznmDlgRef1NControl.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNQuery) this.$refs.PnlWznmDlgMNQuery.handleUpdate(obj);
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
