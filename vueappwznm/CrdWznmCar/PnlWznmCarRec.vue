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
					<PnlWznmCarDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCarDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmCarCar1NPanel
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCarCar1NPanel"
						:scrJref=statshr.scrJrefCar1NPanel
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCar1NDialog
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCar1NDialog"
						:scrJref=statshr.scrJref1NDialog
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCarHk1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCarHk1NControl"
						:scrJref=statshr.scrJrefHk1NControl
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
	import PnlWznmCarDetail from './PnlWznmCarDetail';
	import PnlWznmCarCar1NPanel from './PnlWznmCarCar1NPanel';
	import PnlWznmCar1NDialog from './PnlWznmCar1NDialog';
	import PnlWznmCarHk1NControl from './PnlWznmCarHk1NControl';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmCarRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmCarDetail,
			PnlWznmCarCar1NPanel,
			PnlWznmCar1NDialog,
			PnlWznmCarHk1NControl
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmCarRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCarRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmCarRec) this.continf = dpcheng.ContInfWznmCarRec;
				if (dpcheng.StatAppWznmCarRec) this.statapp = dpcheng.StatAppWznmCarRec;
				if (dpcheng.StatShrWznmCarRec) this.statshr = dpcheng.StatShrWznmCarRec;
				if (dpcheng.TagWznmCarRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmCarRec);
					this.tag = dpcheng.TagWznmCarRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCarDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefCar1NPanel) this.$refs.PnlWznmCarCar1NPanel.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NDialog) this.$refs.PnlWznmCar1NDialog.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NControl) this.$refs.PnlWznmCarHk1NControl.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmCarRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmCarRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCarDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefCar1NPanel) this.$refs.PnlWznmCarCar1NPanel.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NDialog) this.$refs.PnlWznmCar1NDialog.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NControl) this.$refs.PnlWznmCarHk1NControl.handleUpdate(obj);
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
