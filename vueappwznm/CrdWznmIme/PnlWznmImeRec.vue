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
					<PnlWznmImeDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmImeDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmImeIme1NImpexpcol
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmImeIme1NImpexpcol"
						:scrJref=statshr.scrJrefIme1NImpexpcol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmImeSup1NImpexp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmImeSup1NImpexp"
						:scrJref=statshr.scrJrefSup1NImpexp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmImeHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmImeHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
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
	import PnlWznmImeDetail from './PnlWznmImeDetail';
	import PnlWznmImeIme1NImpexpcol from './PnlWznmImeIme1NImpexpcol';
	import PnlWznmImeSup1NImpexp from './PnlWznmImeSup1NImpexp';
	import PnlWznmImeHk1NVector from './PnlWznmImeHk1NVector';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmImeRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmImeDetail,
			PnlWznmImeIme1NImpexpcol,
			PnlWznmImeSup1NImpexp,
			PnlWznmImeHk1NVector
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmImeRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmImeRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmImeRec) this.continf = dpcheng.ContInfWznmImeRec;
				if (dpcheng.StatAppWznmImeRec) this.statapp = dpcheng.StatAppWznmImeRec;
				if (dpcheng.StatShrWznmImeRec) this.statshr = dpcheng.StatShrWznmImeRec;
				if (dpcheng.TagWznmImeRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmImeRec);
					this.tag = dpcheng.TagWznmImeRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmImeDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefIme1NImpexpcol) this.$refs.PnlWznmImeIme1NImpexpcol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NImpexp) this.$refs.PnlWznmImeSup1NImpexp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmImeHk1NVector.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmImeRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmImeRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmImeDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefIme1NImpexpcol) this.$refs.PnlWznmImeIme1NImpexpcol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NImpexp) this.$refs.PnlWznmImeSup1NImpexp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmImeHk1NVector.handleUpdate(obj);
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
