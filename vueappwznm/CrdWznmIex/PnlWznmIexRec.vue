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
					<PnlWznmIexDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmIexDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmIex1NImpexp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmIex1NImpexp"
						:scrJref=statshr.scrJref1NImpexp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmIexHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmIexHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmIexRef1NDialog
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmIexRef1NDialog"
						:scrJref=statshr.scrJrefRef1NDialog
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
	import PnlWznmIexDetail from './PnlWznmIexDetail';
	import PnlWznmIex1NImpexp from './PnlWznmIex1NImpexp';
	import PnlWznmIexHk1NVector from './PnlWznmIexHk1NVector';
	import PnlWznmIexRef1NDialog from './PnlWznmIexRef1NDialog';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmIexRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmIexDetail,
			PnlWznmIex1NImpexp,
			PnlWznmIexHk1NVector,
			PnlWznmIexRef1NDialog
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmIexRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmIexRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmIexRec) this.continf = dpcheng.ContInfWznmIexRec;
				if (dpcheng.StatAppWznmIexRec) this.statapp = dpcheng.StatAppWznmIexRec;
				if (dpcheng.StatShrWznmIexRec) this.statshr = dpcheng.StatShrWznmIexRec;
				if (dpcheng.TagWznmIexRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmIexRec);
					this.tag = dpcheng.TagWznmIexRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmIexDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NImpexp) this.$refs.PnlWznmIex1NImpexp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmIexHk1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NDialog) this.$refs.PnlWznmIexRef1NDialog.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmIexRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmIexRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmIexDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NImpexp) this.$refs.PnlWznmIex1NImpexp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmIexHk1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NDialog) this.$refs.PnlWznmIexRef1NDialog.handleUpdate(obj);
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
