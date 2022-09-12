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
					<PnlWznmBlkDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmBlkDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmBlkAItem
						v-on:request="handleRequest"
						ref="PnlWznmBlkAItem"
						:scrJref=statshr.scrJrefAItem
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmBlk1NRtdpch
						v-on:request="handleRequest"
						ref="PnlWznmBlk1NRtdpch"
						:scrJref=statshr.scrJref1NRtdpch
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmBlkRef1NRtblock
						v-on:request="handleRequest"
						ref="PnlWznmBlkRef1NRtblock"
						:scrJref=statshr.scrJrefRef1NRtblock
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
	import PnlWznmBlkDetail from './PnlWznmBlkDetail';
	import PnlWznmBlkAItem from './PnlWznmBlkAItem';
	import PnlWznmBlk1NRtdpch from './PnlWznmBlk1NRtdpch';
	import PnlWznmBlkRef1NRtblock from './PnlWznmBlkRef1NRtblock';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmBlkRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmBlkDetail,
			PnlWznmBlkAItem,
			PnlWznmBlk1NRtdpch,
			PnlWznmBlkRef1NRtblock
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmBlkRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmBlkRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmBlkRec) this.continf = dpcheng.ContInfWznmBlkRec;
				if (dpcheng.StatAppWznmBlkRec) this.statapp = dpcheng.StatAppWznmBlkRec;
				if (dpcheng.StatShrWznmBlkRec) this.statshr = dpcheng.StatShrWznmBlkRec;
				if (dpcheng.TagWznmBlkRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmBlkRec);
					this.tag = dpcheng.TagWznmBlkRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmBlkDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAItem) this.$refs.PnlWznmBlkAItem.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRtdpch) this.$refs.PnlWznmBlk1NRtdpch.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NRtblock) this.$refs.PnlWznmBlkRef1NRtblock.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmBlkRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmBlkRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmBlkDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAItem) this.$refs.PnlWznmBlkAItem.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRtdpch) this.$refs.PnlWznmBlk1NRtdpch.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NRtblock) this.$refs.PnlWznmBlkRef1NRtblock.handleUpdate(obj);
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
