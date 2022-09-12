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
					<PnlWznmTcoDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTcoDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmTcoATitle
						v-on:request="handleRequest"
						ref="PnlWznmTcoATitle"
						:scrJref=statshr.scrJrefATitle
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmTco1NQuerycol
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTco1NQuerycol"
						:scrJref=statshr.scrJref1NQuerycol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTco1NImpexpcol
						v-on:request="handleRequest"
						ref="PnlWznmTco1NImpexpcol"
						:scrJref=statshr.scrJref1NImpexpcol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTcoRef1NQuerymod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTcoRef1NQuerymod"
						:scrJref=statshr.scrJrefRef1NQuerymod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTcoRef1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTcoRef1NControl"
						:scrJref=statshr.scrJrefRef1NControl
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTco1NCheck
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTco1NCheck"
						:scrJref=statshr.scrJref1NCheck
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
	import PnlWznmTcoDetail from './PnlWznmTcoDetail';
	import PnlWznmTcoATitle from './PnlWznmTcoATitle';
	import PnlWznmTco1NQuerycol from './PnlWznmTco1NQuerycol';
	import PnlWznmTco1NImpexpcol from './PnlWznmTco1NImpexpcol';
	import PnlWznmTcoRef1NQuerymod from './PnlWznmTcoRef1NQuerymod';
	import PnlWznmTcoRef1NControl from './PnlWznmTcoRef1NControl';
	import PnlWznmTco1NCheck from './PnlWznmTco1NCheck';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmTcoRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmTcoDetail,
			PnlWznmTcoATitle,
			PnlWznmTco1NQuerycol,
			PnlWznmTco1NImpexpcol,
			PnlWznmTcoRef1NQuerymod,
			PnlWznmTcoRef1NControl,
			PnlWznmTco1NCheck
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmTcoRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmTcoRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmTcoRec) this.continf = dpcheng.ContInfWznmTcoRec;
				if (dpcheng.StatAppWznmTcoRec) this.statapp = dpcheng.StatAppWznmTcoRec;
				if (dpcheng.StatShrWznmTcoRec) this.statshr = dpcheng.StatShrWznmTcoRec;
				if (dpcheng.TagWznmTcoRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmTcoRec);
					this.tag = dpcheng.TagWznmTcoRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmTcoDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmTcoATitle.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NQuerycol) this.$refs.PnlWznmTco1NQuerycol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NImpexpcol) this.$refs.PnlWznmTco1NImpexpcol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NQuerymod) this.$refs.PnlWznmTcoRef1NQuerymod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NControl) this.$refs.PnlWznmTcoRef1NControl.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCheck) this.$refs.PnlWznmTco1NCheck.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmTcoRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmTcoRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmTcoDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmTcoATitle.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NQuerycol) this.$refs.PnlWznmTco1NQuerycol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NImpexpcol) this.$refs.PnlWznmTco1NImpexpcol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NQuerymod) this.$refs.PnlWznmTcoRef1NQuerymod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NControl) this.$refs.PnlWznmTcoRef1NControl.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCheck) this.$refs.PnlWznmTco1NCheck.handleUpdate(obj);
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
