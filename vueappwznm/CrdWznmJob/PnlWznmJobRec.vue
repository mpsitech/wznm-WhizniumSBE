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
					<PnlWznmJobDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmJobAVar
						v-on:request="handleRequest"
						ref="PnlWznmJobAVar"
						:scrJref=statshr.scrJrefAVar
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobACmd
						v-on:request="handleRequest"
						ref="PnlWznmJobACmd"
						:scrJref=statshr.scrJrefACmd
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmJob1NSensitivity
						v-on:request="handleRequest"
						ref="PnlWznmJob1NSensitivity"
						:scrJref=statshr.scrJref1NSensitivity
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJob1NMethod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJob1NMethod"
						:scrJref=statshr.scrJref1NMethod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJob1NRtjob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJob1NRtjob"
						:scrJref=statshr.scrJref1NRtjob
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobJob1NStage
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobJob1NStage"
						:scrJref=statshr.scrJrefJob1NStage
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobRef1NBlock
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobRef1NBlock"
						:scrJref=statshr.scrJrefRef1NBlock
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobMNOppack
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobMNOppack"
						:scrJref=statshr.scrJrefMNOppack
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobSupMNJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobSupMNJob"
						:scrJref=statshr.scrJrefSupMNJob
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobMNOp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobMNOp"
						:scrJref=statshr.scrJrefMNOp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmJobSubMNJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmJobSubMNJob"
						:scrJref=statshr.scrJrefSubMNJob
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
	import PnlWznmJobDetail from './PnlWznmJobDetail';
	import PnlWznmJobAVar from './PnlWznmJobAVar';
	import PnlWznmJobACmd from './PnlWznmJobACmd';
	import PnlWznmJob1NSensitivity from './PnlWznmJob1NSensitivity';
	import PnlWznmJob1NMethod from './PnlWznmJob1NMethod';
	import PnlWznmJob1NRtjob from './PnlWznmJob1NRtjob';
	import PnlWznmJobJob1NStage from './PnlWznmJobJob1NStage';
	import PnlWznmJobHk1NVector from './PnlWznmJobHk1NVector';
	import PnlWznmJobRef1NBlock from './PnlWznmJobRef1NBlock';
	import PnlWznmJobMNOppack from './PnlWznmJobMNOppack';
	import PnlWznmJobSupMNJob from './PnlWznmJobSupMNJob';
	import PnlWznmJobMNOp from './PnlWznmJobMNOp';
	import PnlWznmJobSubMNJob from './PnlWznmJobSubMNJob';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmJobRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmJobDetail,
			PnlWznmJobAVar,
			PnlWznmJobACmd,
			PnlWznmJob1NSensitivity,
			PnlWznmJob1NMethod,
			PnlWznmJob1NRtjob,
			PnlWznmJobJob1NStage,
			PnlWznmJobHk1NVector,
			PnlWznmJobRef1NBlock,
			PnlWznmJobMNOppack,
			PnlWznmJobSupMNJob,
			PnlWznmJobMNOp,
			PnlWznmJobSubMNJob
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmJobRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmJobRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmJobRec) this.continf = dpcheng.ContInfWznmJobRec;
				if (dpcheng.StatAppWznmJobRec) this.statapp = dpcheng.StatAppWznmJobRec;
				if (dpcheng.StatShrWznmJobRec) this.statshr = dpcheng.StatShrWznmJobRec;
				if (dpcheng.TagWznmJobRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmJobRec);
					this.tag = dpcheng.TagWznmJobRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmJobDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAVar) this.$refs.PnlWznmJobAVar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefACmd) this.$refs.PnlWznmJobACmd.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSensitivity) this.$refs.PnlWznmJob1NSensitivity.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NMethod) this.$refs.PnlWznmJob1NMethod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRtjob) this.$refs.PnlWznmJob1NRtjob.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefJob1NStage) this.$refs.PnlWznmJobJob1NStage.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmJobHk1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NBlock) this.$refs.PnlWznmJobRef1NBlock.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNOppack) this.$refs.PnlWznmJobMNOppack.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSupMNJob) this.$refs.PnlWznmJobSupMNJob.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNOp) this.$refs.PnlWznmJobMNOp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSubMNJob) this.$refs.PnlWznmJobSubMNJob.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmJobRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmJobRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmJobDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAVar) this.$refs.PnlWznmJobAVar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefACmd) this.$refs.PnlWznmJobACmd.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSensitivity) this.$refs.PnlWznmJob1NSensitivity.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NMethod) this.$refs.PnlWznmJob1NMethod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRtjob) this.$refs.PnlWznmJob1NRtjob.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefJob1NStage) this.$refs.PnlWznmJobJob1NStage.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmJobHk1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NBlock) this.$refs.PnlWznmJobRef1NBlock.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNOppack) this.$refs.PnlWznmJobMNOppack.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSupMNJob) this.$refs.PnlWznmJobSupMNJob.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNOp) this.$refs.PnlWznmJobMNOp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSubMNJob) this.$refs.PnlWznmJobSubMNJob.handleUpdate(obj);
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
