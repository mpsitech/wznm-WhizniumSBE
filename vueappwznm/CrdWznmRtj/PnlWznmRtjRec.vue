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
					<PnlWznmRtjDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRtjDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmRtj1NRtdpch
						v-on:request="handleRequest"
						ref="PnlWznmRtj1NRtdpch"
						:scrJref=statshr.scrJref1NRtdpch
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmRtj1NRtblock
						v-on:request="handleRequest"
						ref="PnlWznmRtj1NRtblock"
						:scrJref=statshr.scrJref1NRtblock
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmRtjSup1NRtjob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRtjSup1NRtjob"
						:scrJref=statshr.scrJrefSup1NRtjob
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
	import PnlWznmRtjDetail from './PnlWznmRtjDetail';
	import PnlWznmRtj1NRtdpch from './PnlWznmRtj1NRtdpch';
	import PnlWznmRtj1NRtblock from './PnlWznmRtj1NRtblock';
	import PnlWznmRtjSup1NRtjob from './PnlWznmRtjSup1NRtjob';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmRtjRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmRtjDetail,
			PnlWznmRtj1NRtdpch,
			PnlWznmRtj1NRtblock,
			PnlWznmRtjSup1NRtjob
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmRtjRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmRtjRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmRtjRec) this.continf = dpcheng.ContInfWznmRtjRec;
				if (dpcheng.StatAppWznmRtjRec) this.statapp = dpcheng.StatAppWznmRtjRec;
				if (dpcheng.StatShrWznmRtjRec) this.statshr = dpcheng.StatShrWznmRtjRec;
				if (dpcheng.TagWznmRtjRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmRtjRec);
					this.tag = dpcheng.TagWznmRtjRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmRtjDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRtdpch) this.$refs.PnlWznmRtj1NRtdpch.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRtblock) this.$refs.PnlWznmRtj1NRtblock.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NRtjob) this.$refs.PnlWznmRtjSup1NRtjob.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmRtjRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmRtjRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmRtjDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRtdpch) this.$refs.PnlWznmRtj1NRtdpch.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRtblock) this.$refs.PnlWznmRtj1NRtblock.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NRtjob) this.$refs.PnlWznmRtjSup1NRtjob.handleUpdate(obj);
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
