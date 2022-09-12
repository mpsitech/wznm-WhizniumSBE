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
					<PnlWznmSgeDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSgeDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmSge1NSensitivity
						v-on:request="handleRequest"
						ref="PnlWznmSge1NSensitivity"
						:scrJref=statshr.scrJref1NSensitivity
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSgeSqkMNStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSgeSqkMNStub"
						:scrJref=statshr.scrJrefSqkMNStub
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
	import PnlWznmSgeDetail from './PnlWznmSgeDetail';
	import PnlWznmSge1NSensitivity from './PnlWznmSge1NSensitivity';
	import PnlWznmSgeSqkMNStub from './PnlWznmSgeSqkMNStub';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmSgeRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmSgeDetail,
			PnlWznmSge1NSensitivity,
			PnlWznmSgeSqkMNStub
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmSgeRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmSgeRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmSgeRec) this.continf = dpcheng.ContInfWznmSgeRec;
				if (dpcheng.StatAppWznmSgeRec) this.statapp = dpcheng.StatAppWznmSgeRec;
				if (dpcheng.StatShrWznmSgeRec) this.statshr = dpcheng.StatShrWznmSgeRec;
				if (dpcheng.TagWznmSgeRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmSgeRec);
					this.tag = dpcheng.TagWznmSgeRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmSgeDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSensitivity) this.$refs.PnlWznmSge1NSensitivity.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSqkMNStub) this.$refs.PnlWznmSgeSqkMNStub.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmSgeRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmSgeRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmSgeDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSensitivity) this.$refs.PnlWznmSge1NSensitivity.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSqkMNStub) this.$refs.PnlWznmSgeSqkMNStub.handleUpdate(obj);
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
