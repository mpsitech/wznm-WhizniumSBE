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
					<PnlWznmPrjDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPrjDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmPrjPrj1NVersion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPrjPrj1NVersion"
						:scrJref=statshr.scrJrefPrj1NVersion
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmPrjMNPerson
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmPrjMNPerson"
						:scrJref=statshr.scrJrefMNPerson
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
	import PnlWznmPrjDetail from './PnlWznmPrjDetail';
	import PnlWznmPrjPrj1NVersion from './PnlWznmPrjPrj1NVersion';
	import PnlWznmPrjMNPerson from './PnlWznmPrjMNPerson';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmPrjRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmPrjDetail,
			PnlWznmPrjPrj1NVersion,
			PnlWznmPrjMNPerson
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmPrjRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmPrjRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmPrjRec) this.continf = dpcheng.ContInfWznmPrjRec;
				if (dpcheng.StatAppWznmPrjRec) this.statapp = dpcheng.StatAppWznmPrjRec;
				if (dpcheng.StatShrWznmPrjRec) this.statshr = dpcheng.StatShrWznmPrjRec;
				if (dpcheng.TagWznmPrjRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmPrjRec);
					this.tag = dpcheng.TagWznmPrjRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmPrjDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefPrj1NVersion) this.$refs.PnlWznmPrjPrj1NVersion.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNPerson) this.$refs.PnlWznmPrjMNPerson.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmPrjRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmPrjRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmPrjDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefPrj1NVersion) this.$refs.PnlWznmPrjPrj1NVersion.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNPerson) this.$refs.PnlWznmPrjMNPerson.handleUpdate(obj);
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
