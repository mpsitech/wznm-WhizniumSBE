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
					<PnlWznmConDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmConDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmConAPar
						v-on:request="handleRequest"
						ref="PnlWznmConAPar"
						:scrJref=statshr.scrJrefAPar
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmConSup1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmConSup1NControl"
						:scrJref=statshr.scrJrefSup1NControl
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmConFedRef1NRtblock
						v-on:request="handleRequest"
						ref="PnlWznmConFedRef1NRtblock"
						:scrJref=statshr.scrJrefFedRef1NRtblock
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
	import PnlWznmConDetail from './PnlWznmConDetail';
	import PnlWznmConAPar from './PnlWznmConAPar';
	import PnlWznmConSup1NControl from './PnlWznmConSup1NControl';
	import PnlWznmConFedRef1NRtblock from './PnlWznmConFedRef1NRtblock';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmConRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmConDetail,
			PnlWznmConAPar,
			PnlWznmConSup1NControl,
			PnlWznmConFedRef1NRtblock
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmConRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmConRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmConRec) this.continf = dpcheng.ContInfWznmConRec;
				if (dpcheng.StatAppWznmConRec) this.statapp = dpcheng.StatAppWznmConRec;
				if (dpcheng.StatShrWznmConRec) this.statshr = dpcheng.StatShrWznmConRec;
				if (dpcheng.TagWznmConRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmConRec);
					this.tag = dpcheng.TagWznmConRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmConDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWznmConAPar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NControl) this.$refs.PnlWznmConSup1NControl.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFedRef1NRtblock) this.$refs.PnlWznmConFedRef1NRtblock.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmConRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmConRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmConDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWznmConAPar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NControl) this.$refs.PnlWznmConSup1NControl.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFedRef1NRtblock) this.$refs.PnlWznmConFedRef1NRtblock.handleUpdate(obj);
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
