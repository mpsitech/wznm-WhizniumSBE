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
					<PnlWznmOpxDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpxDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmOpxARetval
						v-on:request="handleRequest"
						ref="PnlWznmOpxARetval"
						:scrJref=statshr.scrJrefARetval
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpxAInvarg
						v-on:request="handleRequest"
						ref="PnlWznmOpxAInvarg"
						:scrJref=statshr.scrJrefAInvarg
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmOpxRef1NBlock
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpxRef1NBlock"
						:scrJref=statshr.scrJrefRef1NBlock
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpxMNJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpxMNJob"
						:scrJref=statshr.scrJrefMNJob
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpxSqkMNStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpxSqkMNStub"
						:scrJref=statshr.scrJrefSqkMNStub
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
	import PnlWznmOpxDetail from './PnlWznmOpxDetail';
	import PnlWznmOpxARetval from './PnlWznmOpxARetval';
	import PnlWznmOpxAInvarg from './PnlWznmOpxAInvarg';
	import PnlWznmOpxRef1NBlock from './PnlWznmOpxRef1NBlock';
	import PnlWznmOpxMNJob from './PnlWznmOpxMNJob';
	import PnlWznmOpxSqkMNStub from './PnlWznmOpxSqkMNStub';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmOpxRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmOpxDetail,
			PnlWznmOpxARetval,
			PnlWznmOpxAInvarg,
			PnlWznmOpxRef1NBlock,
			PnlWznmOpxMNJob,
			PnlWznmOpxSqkMNStub
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmOpxRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmOpxRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmOpxRec) this.continf = dpcheng.ContInfWznmOpxRec;
				if (dpcheng.StatAppWznmOpxRec) this.statapp = dpcheng.StatAppWznmOpxRec;
				if (dpcheng.StatShrWznmOpxRec) this.statshr = dpcheng.StatShrWznmOpxRec;
				if (dpcheng.TagWznmOpxRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmOpxRec);
					this.tag = dpcheng.TagWznmOpxRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmOpxDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefARetval) this.$refs.PnlWznmOpxARetval.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAInvarg) this.$refs.PnlWznmOpxAInvarg.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NBlock) this.$refs.PnlWznmOpxRef1NBlock.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNJob) this.$refs.PnlWznmOpxMNJob.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSqkMNStub) this.$refs.PnlWznmOpxSqkMNStub.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmOpxRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmOpxRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmOpxDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefARetval) this.$refs.PnlWznmOpxARetval.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAInvarg) this.$refs.PnlWznmOpxAInvarg.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NBlock) this.$refs.PnlWznmOpxRef1NBlock.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNJob) this.$refs.PnlWznmOpxMNJob.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSqkMNStub) this.$refs.PnlWznmOpxSqkMNStub.handleUpdate(obj);
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
