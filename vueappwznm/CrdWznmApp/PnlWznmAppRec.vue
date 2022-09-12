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
					<PnlWznmAppDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmAppDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmApp1NEvent
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmApp1NEvent"
						:scrJref=statshr.scrJref1NEvent
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmApp1NRtjob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmApp1NRtjob"
						:scrJref=statshr.scrJref1NRtjob
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmAppApp1NSequence
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmAppApp1NSequence"
						:scrJref=statshr.scrJrefApp1NSequence
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmAppRef1NFile
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmAppRef1NFile"
						:scrJref=statshr.scrJrefRef1NFile
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
	import PnlWznmAppDetail from './PnlWznmAppDetail';
	import PnlWznmApp1NEvent from './PnlWznmApp1NEvent';
	import PnlWznmApp1NRtjob from './PnlWznmApp1NRtjob';
	import PnlWznmAppApp1NSequence from './PnlWznmAppApp1NSequence';
	import PnlWznmAppRef1NFile from './PnlWznmAppRef1NFile';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmAppRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmAppDetail,
			PnlWznmApp1NEvent,
			PnlWznmApp1NRtjob,
			PnlWznmAppApp1NSequence,
			PnlWznmAppRef1NFile
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmAppRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmAppRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmAppRec) this.continf = dpcheng.ContInfWznmAppRec;
				if (dpcheng.StatAppWznmAppRec) this.statapp = dpcheng.StatAppWznmAppRec;
				if (dpcheng.StatShrWznmAppRec) this.statshr = dpcheng.StatShrWznmAppRec;
				if (dpcheng.TagWznmAppRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmAppRec);
					this.tag = dpcheng.TagWznmAppRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmAppDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NEvent) this.$refs.PnlWznmApp1NEvent.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRtjob) this.$refs.PnlWznmApp1NRtjob.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefApp1NSequence) this.$refs.PnlWznmAppApp1NSequence.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWznmAppRef1NFile.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmAppRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmAppRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmAppDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NEvent) this.$refs.PnlWznmApp1NEvent.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRtjob) this.$refs.PnlWznmApp1NRtjob.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefApp1NSequence) this.$refs.PnlWznmAppApp1NSequence.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWznmAppRef1NFile.handleUpdate(obj);
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
