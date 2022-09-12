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
					<PnlWznmOpkDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpkDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmOpkARetval
						v-on:request="handleRequest"
						ref="PnlWznmOpkARetval"
						:scrJref=statshr.scrJrefARetval
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpkAInvarg
						v-on:request="handleRequest"
						ref="PnlWznmOpkAInvarg"
						:scrJref=statshr.scrJrefAInvarg
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmOpk1NOp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpk1NOp"
						:scrJref=statshr.scrJref1NOp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpkRef1NBlock
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpkRef1NBlock"
						:scrJref=statshr.scrJrefRef1NBlock
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpkMNJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpkMNJob"
						:scrJref=statshr.scrJrefMNJob
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpkMNComponent
						v-on:request="handleRequest"
						ref="PnlWznmOpkMNComponent"
						:scrJref=statshr.scrJrefMNComponent
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpkMNLibrary
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpkMNLibrary"
						:scrJref=statshr.scrJrefMNLibrary
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmOpkSqkMNStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmOpkSqkMNStub"
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
	import PnlWznmOpkDetail from './PnlWznmOpkDetail';
	import PnlWznmOpkARetval from './PnlWznmOpkARetval';
	import PnlWznmOpkAInvarg from './PnlWznmOpkAInvarg';
	import PnlWznmOpk1NOp from './PnlWznmOpk1NOp';
	import PnlWznmOpkRef1NBlock from './PnlWznmOpkRef1NBlock';
	import PnlWznmOpkMNJob from './PnlWznmOpkMNJob';
	import PnlWznmOpkMNComponent from './PnlWznmOpkMNComponent';
	import PnlWznmOpkMNLibrary from './PnlWznmOpkMNLibrary';
	import PnlWznmOpkSqkMNStub from './PnlWznmOpkSqkMNStub';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmOpkRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmOpkDetail,
			PnlWznmOpkARetval,
			PnlWznmOpkAInvarg,
			PnlWznmOpk1NOp,
			PnlWznmOpkRef1NBlock,
			PnlWznmOpkMNJob,
			PnlWznmOpkMNComponent,
			PnlWznmOpkMNLibrary,
			PnlWznmOpkSqkMNStub
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmOpkRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmOpkRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmOpkRec) this.continf = dpcheng.ContInfWznmOpkRec;
				if (dpcheng.StatAppWznmOpkRec) this.statapp = dpcheng.StatAppWznmOpkRec;
				if (dpcheng.StatShrWznmOpkRec) this.statshr = dpcheng.StatShrWznmOpkRec;
				if (dpcheng.TagWznmOpkRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmOpkRec);
					this.tag = dpcheng.TagWznmOpkRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmOpkDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefARetval) this.$refs.PnlWznmOpkARetval.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAInvarg) this.$refs.PnlWznmOpkAInvarg.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NOp) this.$refs.PnlWznmOpk1NOp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NBlock) this.$refs.PnlWznmOpkRef1NBlock.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNJob) this.$refs.PnlWznmOpkMNJob.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNComponent) this.$refs.PnlWznmOpkMNComponent.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLibrary) this.$refs.PnlWznmOpkMNLibrary.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSqkMNStub) this.$refs.PnlWznmOpkSqkMNStub.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmOpkRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmOpkRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmOpkDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefARetval) this.$refs.PnlWznmOpkARetval.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAInvarg) this.$refs.PnlWznmOpkAInvarg.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NOp) this.$refs.PnlWznmOpk1NOp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NBlock) this.$refs.PnlWznmOpkRef1NBlock.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNJob) this.$refs.PnlWznmOpkMNJob.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNComponent) this.$refs.PnlWznmOpkMNComponent.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLibrary) this.$refs.PnlWznmOpkMNLibrary.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSqkMNStub) this.$refs.PnlWznmOpkSqkMNStub.handleUpdate(obj);
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
