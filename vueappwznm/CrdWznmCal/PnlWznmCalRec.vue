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
					<PnlWznmCalDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCalDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmCal1NSensitivity
						v-on:request="handleRequest"
						ref="PnlWznmCal1NSensitivity"
						:scrJref=statshr.scrJref1NSensitivity
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCalMNStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCalMNStub"
						:scrJref=statshr.scrJrefMNStub
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
	import PnlWznmCalDetail from './PnlWznmCalDetail';
	import PnlWznmCal1NSensitivity from './PnlWznmCal1NSensitivity';
	import PnlWznmCalMNStub from './PnlWznmCalMNStub';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmCalRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmCalDetail,
			PnlWznmCal1NSensitivity,
			PnlWznmCalMNStub
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmCalRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCalRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmCalRec) this.continf = dpcheng.ContInfWznmCalRec;
				if (dpcheng.StatAppWznmCalRec) this.statapp = dpcheng.StatAppWznmCalRec;
				if (dpcheng.StatShrWznmCalRec) this.statshr = dpcheng.StatShrWznmCalRec;
				if (dpcheng.TagWznmCalRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmCalRec);
					this.tag = dpcheng.TagWznmCalRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCalDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSensitivity) this.$refs.PnlWznmCal1NSensitivity.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNStub) this.$refs.PnlWznmCalMNStub.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmCalRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmCalRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCalDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSensitivity) this.$refs.PnlWznmCal1NSensitivity.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNStub) this.$refs.PnlWznmCalMNStub.handleUpdate(obj);
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
