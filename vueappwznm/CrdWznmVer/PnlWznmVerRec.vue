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
					<PnlWznmVerDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmVerVer1NVisual
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerVer1NVisual"
						:scrJref=statshr.scrJrefVer1NVisual
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVerVer1NError
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerVer1NError"
						:scrJref=statshr.scrJrefVer1NError
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVerVer1NApp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerVer1NApp"
						:scrJref=statshr.scrJrefVer1NApp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NCapability
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NCapability"
						:scrJref=statshr.scrJref1NCapability
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NVector"
						:scrJref=statshr.scrJref1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NTable
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NTable"
						:scrJref=statshr.scrJref1NTable
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NRelation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NRelation"
						:scrJref=statshr.scrJref1NRelation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NQuery
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NQuery"
						:scrJref=statshr.scrJref1NQuery
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NPreset
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NPreset"
						:scrJref=statshr.scrJref1NPreset
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVerVer1NModule
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerVer1NModule"
						:scrJref=statshr.scrJrefVer1NModule
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NOppack
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NOppack"
						:scrJref=statshr.scrJref1NOppack
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NJob
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NJob"
						:scrJref=statshr.scrJref1NJob
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NImpexpcplx
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NImpexpcplx"
						:scrJref=statshr.scrJref1NImpexpcplx
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NCall
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NCall"
						:scrJref=statshr.scrJref1NCall
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NComponent
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NComponent"
						:scrJref=statshr.scrJref1NComponent
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVerBvr1NVersion
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerBvr1NVersion"
						:scrJref=statshr.scrJrefBvr1NVersion
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVer1NBlock
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVer1NBlock"
						:scrJref=statshr.scrJref1NBlock
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVerRef1NFile
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerRef1NFile"
						:scrJref=statshr.scrJrefRef1NFile
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVerMNLocale
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVerMNLocale"
						:scrJref=statshr.scrJrefMNLocale
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
	import PnlWznmVerDetail from './PnlWznmVerDetail';
	import PnlWznmVerVer1NVisual from './PnlWznmVerVer1NVisual';
	import PnlWznmVerVer1NError from './PnlWznmVerVer1NError';
	import PnlWznmVerVer1NApp from './PnlWznmVerVer1NApp';
	import PnlWznmVer1NCapability from './PnlWznmVer1NCapability';
	import PnlWznmVer1NVector from './PnlWznmVer1NVector';
	import PnlWznmVer1NTable from './PnlWznmVer1NTable';
	import PnlWznmVer1NRelation from './PnlWznmVer1NRelation';
	import PnlWznmVer1NQuery from './PnlWznmVer1NQuery';
	import PnlWznmVer1NPreset from './PnlWznmVer1NPreset';
	import PnlWznmVerVer1NModule from './PnlWznmVerVer1NModule';
	import PnlWznmVer1NOppack from './PnlWznmVer1NOppack';
	import PnlWznmVer1NJob from './PnlWznmVer1NJob';
	import PnlWznmVer1NImpexpcplx from './PnlWznmVer1NImpexpcplx';
	import PnlWznmVer1NCall from './PnlWznmVer1NCall';
	import PnlWznmVer1NComponent from './PnlWznmVer1NComponent';
	import PnlWznmVerBvr1NVersion from './PnlWznmVerBvr1NVersion';
	import PnlWznmVer1NBlock from './PnlWznmVer1NBlock';
	import PnlWznmVerRef1NFile from './PnlWznmVerRef1NFile';
	import PnlWznmVerMNLocale from './PnlWznmVerMNLocale';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmVerRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmVerDetail,
			PnlWznmVerVer1NVisual,
			PnlWznmVerVer1NError,
			PnlWznmVerVer1NApp,
			PnlWznmVer1NCapability,
			PnlWznmVer1NVector,
			PnlWznmVer1NTable,
			PnlWznmVer1NRelation,
			PnlWznmVer1NQuery,
			PnlWznmVer1NPreset,
			PnlWznmVerVer1NModule,
			PnlWznmVer1NOppack,
			PnlWznmVer1NJob,
			PnlWznmVer1NImpexpcplx,
			PnlWznmVer1NCall,
			PnlWznmVer1NComponent,
			PnlWznmVerBvr1NVersion,
			PnlWznmVer1NBlock,
			PnlWznmVerRef1NFile,
			PnlWznmVerMNLocale
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmVerRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmVerRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmVerRec) this.continf = dpcheng.ContInfWznmVerRec;
				if (dpcheng.StatAppWznmVerRec) this.statapp = dpcheng.StatAppWznmVerRec;
				if (dpcheng.StatShrWznmVerRec) this.statshr = dpcheng.StatShrWznmVerRec;
				if (dpcheng.TagWznmVerRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmVerRec);
					this.tag = dpcheng.TagWznmVerRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmVerDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefVer1NVisual) this.$refs.PnlWznmVerVer1NVisual.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefVer1NError) this.$refs.PnlWznmVerVer1NError.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefVer1NApp) this.$refs.PnlWznmVerVer1NApp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCapability) this.$refs.PnlWznmVer1NCapability.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NVector) this.$refs.PnlWznmVer1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NTable) this.$refs.PnlWznmVer1NTable.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRelation) this.$refs.PnlWznmVer1NRelation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NQuery) this.$refs.PnlWznmVer1NQuery.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NPreset) this.$refs.PnlWznmVer1NPreset.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefVer1NModule) this.$refs.PnlWznmVerVer1NModule.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NOppack) this.$refs.PnlWznmVer1NOppack.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NJob) this.$refs.PnlWznmVer1NJob.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NImpexpcplx) this.$refs.PnlWznmVer1NImpexpcplx.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCall) this.$refs.PnlWznmVer1NCall.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NComponent) this.$refs.PnlWznmVer1NComponent.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefBvr1NVersion) this.$refs.PnlWznmVerBvr1NVersion.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NBlock) this.$refs.PnlWznmVer1NBlock.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWznmVerRef1NFile.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNLocale) this.$refs.PnlWznmVerMNLocale.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmVerRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmVerRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmVerDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefVer1NVisual) this.$refs.PnlWznmVerVer1NVisual.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefVer1NError) this.$refs.PnlWznmVerVer1NError.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefVer1NApp) this.$refs.PnlWznmVerVer1NApp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCapability) this.$refs.PnlWznmVer1NCapability.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NVector) this.$refs.PnlWznmVer1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NTable) this.$refs.PnlWznmVer1NTable.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRelation) this.$refs.PnlWznmVer1NRelation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NQuery) this.$refs.PnlWznmVer1NQuery.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NPreset) this.$refs.PnlWznmVer1NPreset.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefVer1NModule) this.$refs.PnlWznmVerVer1NModule.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NOppack) this.$refs.PnlWznmVer1NOppack.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NJob) this.$refs.PnlWznmVer1NJob.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NImpexpcplx) this.$refs.PnlWznmVer1NImpexpcplx.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCall) this.$refs.PnlWznmVer1NCall.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NComponent) this.$refs.PnlWznmVer1NComponent.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefBvr1NVersion) this.$refs.PnlWznmVerBvr1NVersion.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NBlock) this.$refs.PnlWznmVer1NBlock.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWznmVerRef1NFile.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNLocale) this.$refs.PnlWznmVerMNLocale.handleUpdate(obj);
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
