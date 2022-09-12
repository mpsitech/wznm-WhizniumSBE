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
					<PnlWznmCmpDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCmpDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmCmp1NRelease
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCmp1NRelease"
						:scrJref=statshr.scrJref1NRelease
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCmpMNOppack
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCmpMNOppack"
						:scrJref=statshr.scrJrefMNOppack
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCmpMNLibrary
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCmpMNLibrary"
						:scrJref=statshr.scrJrefMNLibrary
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
	import PnlWznmCmpDetail from './PnlWznmCmpDetail';
	import PnlWznmCmp1NRelease from './PnlWznmCmp1NRelease';
	import PnlWznmCmpMNOppack from './PnlWznmCmpMNOppack';
	import PnlWznmCmpMNLibrary from './PnlWznmCmpMNLibrary';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmCmpRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmCmpDetail,
			PnlWznmCmp1NRelease,
			PnlWznmCmpMNOppack,
			PnlWznmCmpMNLibrary
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmCmpRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCmpRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmCmpRec) this.continf = dpcheng.ContInfWznmCmpRec;
				if (dpcheng.StatAppWznmCmpRec) this.statapp = dpcheng.StatAppWznmCmpRec;
				if (dpcheng.StatShrWznmCmpRec) this.statshr = dpcheng.StatShrWznmCmpRec;
				if (dpcheng.TagWznmCmpRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmCmpRec);
					this.tag = dpcheng.TagWznmCmpRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCmpDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWznmCmp1NRelease.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNOppack) this.$refs.PnlWznmCmpMNOppack.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLibrary) this.$refs.PnlWznmCmpMNLibrary.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmCmpRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmCmpRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCmpDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWznmCmp1NRelease.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNOppack) this.$refs.PnlWznmCmpMNOppack.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLibrary) this.$refs.PnlWznmCmpMNLibrary.handleUpdate(obj);
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
