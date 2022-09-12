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
					<PnlWznmVecDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVecDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmVecATitle
						v-on:request="handleRequest"
						ref="PnlWznmVecATitle"
						:scrJref=statshr.scrJrefATitle
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmVecVec1NVectoritem
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVecVec1NVectoritem"
						:scrJref=statshr.scrJrefVec1NVectoritem
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVecFct1NTablecol
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVecFct1NTablecol"
						:scrJref=statshr.scrJrefFct1NTablecol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVecRef1NPanel
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVecRef1NPanel"
						:scrJref=statshr.scrJrefRef1NPanel
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVecSrc1NFeed
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVecSrc1NFeed"
						:scrJref=statshr.scrJrefSrc1NFeed
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVecPst1NQuerymod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmVecPst1NQuerymod"
						:scrJref=statshr.scrJrefPst1NQuerymod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmVecMNTable
						v-on:request="handleRequest"
						ref="PnlWznmVecMNTable"
						:scrJref=statshr.scrJrefMNTable
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
	import PnlWznmVecDetail from './PnlWznmVecDetail';
	import PnlWznmVecATitle from './PnlWznmVecATitle';
	import PnlWznmVecVec1NVectoritem from './PnlWznmVecVec1NVectoritem';
	import PnlWznmVecFct1NTablecol from './PnlWznmVecFct1NTablecol';
	import PnlWznmVecRef1NPanel from './PnlWznmVecRef1NPanel';
	import PnlWznmVecSrc1NFeed from './PnlWznmVecSrc1NFeed';
	import PnlWznmVecPst1NQuerymod from './PnlWznmVecPst1NQuerymod';
	import PnlWznmVecMNTable from './PnlWznmVecMNTable';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmVecRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmVecDetail,
			PnlWznmVecATitle,
			PnlWznmVecVec1NVectoritem,
			PnlWznmVecFct1NTablecol,
			PnlWznmVecRef1NPanel,
			PnlWznmVecSrc1NFeed,
			PnlWznmVecPst1NQuerymod,
			PnlWznmVecMNTable
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmVecRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmVecRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmVecRec) this.continf = dpcheng.ContInfWznmVecRec;
				if (dpcheng.StatAppWznmVecRec) this.statapp = dpcheng.StatAppWznmVecRec;
				if (dpcheng.StatShrWznmVecRec) this.statshr = dpcheng.StatShrWznmVecRec;
				if (dpcheng.TagWznmVecRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmVecRec);
					this.tag = dpcheng.TagWznmVecRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmVecDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmVecATitle.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefVec1NVectoritem) this.$refs.PnlWznmVecVec1NVectoritem.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFct1NTablecol) this.$refs.PnlWznmVecFct1NTablecol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmVecRef1NPanel.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSrc1NFeed) this.$refs.PnlWznmVecSrc1NFeed.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefPst1NQuerymod) this.$refs.PnlWznmVecPst1NQuerymod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNTable) this.$refs.PnlWznmVecMNTable.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmVecRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmVecRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmVecDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmVecATitle.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefVec1NVectoritem) this.$refs.PnlWznmVecVec1NVectoritem.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFct1NTablecol) this.$refs.PnlWznmVecFct1NTablecol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmVecRef1NPanel.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSrc1NFeed) this.$refs.PnlWznmVecSrc1NFeed.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefPst1NQuerymod) this.$refs.PnlWznmVecPst1NQuerymod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNTable) this.$refs.PnlWznmVecMNTable.handleUpdate(obj);
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
