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
					<PnlWznmPnlDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPnlDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmPnlHk1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPnlHk1NControl"
						:scrJref=statshr.scrJrefHk1NControl
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmPnlMNQuery
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPnlMNQuery"
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
	import PnlWznmPnlDetail from './PnlWznmPnlDetail';
	import PnlWznmPnlHk1NControl from './PnlWznmPnlHk1NControl';
	import PnlWznmPnlMNQuery from './PnlWznmPnlMNQuery';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmPnlRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmPnlDetail,
			PnlWznmPnlHk1NControl,
			PnlWznmPnlMNQuery
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmPnlRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmPnlRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmPnlRec) this.continf = dpcheng.ContInfWznmPnlRec;
				if (dpcheng.StatAppWznmPnlRec) this.statapp = dpcheng.StatAppWznmPnlRec;
				if (dpcheng.StatShrWznmPnlRec) this.statshr = dpcheng.StatShrWznmPnlRec;
				if (dpcheng.TagWznmPnlRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmPnlRec);
					this.tag = dpcheng.TagWznmPnlRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmPnlDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NControl) this.$refs.PnlWznmPnlHk1NControl.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNQuery) this.$refs.PnlWznmPnlMNQuery.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmPnlRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmPnlRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmPnlDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NControl) this.$refs.PnlWznmPnlHk1NControl.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNQuery) this.$refs.PnlWznmPnlMNQuery.handleUpdate(obj);
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
