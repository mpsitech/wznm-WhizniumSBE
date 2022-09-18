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
					<PnlWznmStbDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmStbDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmStbSupMNStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmStbSupMNStub"
						:scrJref=statshr.scrJrefSupMNStub
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmStbMNCall
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmStbMNCall"
						:scrJref=statshr.scrJrefMNCall
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmStbSubMNStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmStbSubMNStub"
						:scrJref=statshr.scrJrefSubMNStub
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmStbMNSquawk
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmStbMNSquawk"
						:scrJref=statshr.scrJrefMNSquawk
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
	import PnlWznmStbDetail from './PnlWznmStbDetail';
	import PnlWznmStbSupMNStub from './PnlWznmStbSupMNStub';
	import PnlWznmStbMNCall from './PnlWznmStbMNCall';
	import PnlWznmStbSubMNStub from './PnlWznmStbSubMNStub';
	import PnlWznmStbMNSquawk from './PnlWznmStbMNSquawk';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmStbRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmStbDetail,
			PnlWznmStbSupMNStub,
			PnlWznmStbMNCall,
			PnlWznmStbSubMNStub,
			PnlWznmStbMNSquawk
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmStbRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmStbRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmStbRec) this.continf = dpcheng.ContInfWznmStbRec;
				if (dpcheng.StatAppWznmStbRec) this.statapp = dpcheng.StatAppWznmStbRec;
				if (dpcheng.StatShrWznmStbRec) this.statshr = dpcheng.StatShrWznmStbRec;
				if (dpcheng.TagWznmStbRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmStbRec);
					this.tag = dpcheng.TagWznmStbRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmStbDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSupMNStub) this.$refs.PnlWznmStbSupMNStub.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNCall) this.$refs.PnlWznmStbMNCall.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSubMNStub) this.$refs.PnlWznmStbSubMNStub.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNSquawk) this.$refs.PnlWznmStbMNSquawk.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmStbRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmStbRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmStbDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSupMNStub) this.$refs.PnlWznmStbSupMNStub.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNCall) this.$refs.PnlWznmStbMNCall.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSubMNStub) this.$refs.PnlWznmStbSubMNStub.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNSquawk) this.$refs.PnlWznmStbMNSquawk.handleUpdate(obj);
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
