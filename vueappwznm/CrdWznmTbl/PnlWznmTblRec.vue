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
					<PnlWznmTblDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmTblALoadfct
						v-on:request="handleRequest"
						ref="PnlWznmTblALoadfct"
						:scrJref=statshr.scrJrefALoadfct
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblATitle
						v-on:request="handleRequest"
						ref="PnlWznmTblATitle"
						:scrJref=statshr.scrJrefATitle
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmTbl1NImpexp
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTbl1NImpexp"
						:scrJref=statshr.scrJref1NImpexp
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTbl1NStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTbl1NStub"
						:scrJref=statshr.scrJref1NStub
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTbl1NSubset
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTbl1NSubset"
						:scrJref=statshr.scrJref1NSubset
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblTbl1NTablecol
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblTbl1NTablecol"
						:scrJref=statshr.scrJrefTbl1NTablecol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblFr1NRelation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblFr1NRelation"
						:scrJref=statshr.scrJrefFr1NRelation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblTo1NRelation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblTo1NRelation"
						:scrJref=statshr.scrJrefTo1NRelation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTbl1NCheck
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTbl1NCheck"
						:scrJref=statshr.scrJref1NCheck
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblSrc1NFeed
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblSrc1NFeed"
						:scrJref=statshr.scrJrefSrc1NFeed
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblRef1NCall
						v-on:request="handleRequest"
						ref="PnlWznmTblRef1NCall"
						:scrJref=statshr.scrJrefRef1NCall
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblRef1NDialog
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblRef1NDialog"
						:scrJref=statshr.scrJrefRef1NDialog
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblRef1NQuerymod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblRef1NQuerymod"
						:scrJref=statshr.scrJrefRef1NQuerymod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblFct1NTablecol
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblFct1NTablecol"
						:scrJref=statshr.scrJrefFct1NTablecol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblRef1NRtblock
						v-on:request="handleRequest"
						ref="PnlWznmTblRef1NRtblock"
						:scrJref=statshr.scrJrefRef1NRtblock
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblHk1NVector
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblHk1NVector"
						:scrJref=statshr.scrJrefHk1NVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblRef1NPanel
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblRef1NPanel"
						:scrJref=statshr.scrJrefRef1NPanel
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblPst1NQuerymod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblPst1NQuerymod"
						:scrJref=statshr.scrJrefPst1NQuerymod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblMNVector
						v-on:request="handleRequest"
						ref="PnlWznmTblMNVector"
						:scrJref=statshr.scrJrefMNVector
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmTblMNQuery
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmTblMNQuery"
						:scrJref=statshr.scrJrefMNQuery
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
	import PnlWznmTblDetail from './PnlWznmTblDetail';
	import PnlWznmTblALoadfct from './PnlWznmTblALoadfct';
	import PnlWznmTblATitle from './PnlWznmTblATitle';
	import PnlWznmTbl1NImpexp from './PnlWznmTbl1NImpexp';
	import PnlWznmTbl1NStub from './PnlWznmTbl1NStub';
	import PnlWznmTbl1NSubset from './PnlWznmTbl1NSubset';
	import PnlWznmTblTbl1NTablecol from './PnlWznmTblTbl1NTablecol';
	import PnlWznmTblFr1NRelation from './PnlWznmTblFr1NRelation';
	import PnlWznmTblTo1NRelation from './PnlWznmTblTo1NRelation';
	import PnlWznmTbl1NCheck from './PnlWznmTbl1NCheck';
	import PnlWznmTblSrc1NFeed from './PnlWznmTblSrc1NFeed';
	import PnlWznmTblRef1NCall from './PnlWznmTblRef1NCall';
	import PnlWznmTblRef1NDialog from './PnlWznmTblRef1NDialog';
	import PnlWznmTblRef1NQuerymod from './PnlWznmTblRef1NQuerymod';
	import PnlWznmTblFct1NTablecol from './PnlWznmTblFct1NTablecol';
	import PnlWznmTblRef1NRtblock from './PnlWznmTblRef1NRtblock';
	import PnlWznmTblHk1NVector from './PnlWznmTblHk1NVector';
	import PnlWznmTblRef1NPanel from './PnlWznmTblRef1NPanel';
	import PnlWznmTblPst1NQuerymod from './PnlWznmTblPst1NQuerymod';
	import PnlWznmTblMNVector from './PnlWznmTblMNVector';
	import PnlWznmTblMNQuery from './PnlWznmTblMNQuery';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmTblRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmTblDetail,
			PnlWznmTblALoadfct,
			PnlWznmTblATitle,
			PnlWznmTbl1NImpexp,
			PnlWznmTbl1NStub,
			PnlWznmTbl1NSubset,
			PnlWznmTblTbl1NTablecol,
			PnlWznmTblFr1NRelation,
			PnlWznmTblTo1NRelation,
			PnlWznmTbl1NCheck,
			PnlWznmTblSrc1NFeed,
			PnlWznmTblRef1NCall,
			PnlWznmTblRef1NDialog,
			PnlWznmTblRef1NQuerymod,
			PnlWznmTblFct1NTablecol,
			PnlWznmTblRef1NRtblock,
			PnlWznmTblHk1NVector,
			PnlWznmTblRef1NPanel,
			PnlWznmTblPst1NQuerymod,
			PnlWznmTblMNVector,
			PnlWznmTblMNQuery
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmTblRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmTblRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmTblRec) this.continf = dpcheng.ContInfWznmTblRec;
				if (dpcheng.StatAppWznmTblRec) this.statapp = dpcheng.StatAppWznmTblRec;
				if (dpcheng.StatShrWznmTblRec) this.statshr = dpcheng.StatShrWznmTblRec;
				if (dpcheng.TagWznmTblRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmTblRec);
					this.tag = dpcheng.TagWznmTblRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmTblDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefALoadfct) this.$refs.PnlWznmTblALoadfct.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmTblATitle.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NImpexp) this.$refs.PnlWznmTbl1NImpexp.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NStub) this.$refs.PnlWznmTbl1NStub.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSubset) this.$refs.PnlWznmTbl1NSubset.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefTbl1NTablecol) this.$refs.PnlWznmTblTbl1NTablecol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFr1NRelation) this.$refs.PnlWznmTblFr1NRelation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefTo1NRelation) this.$refs.PnlWznmTblTo1NRelation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NCheck) this.$refs.PnlWznmTbl1NCheck.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSrc1NFeed) this.$refs.PnlWznmTblSrc1NFeed.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NCall) this.$refs.PnlWznmTblRef1NCall.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NDialog) this.$refs.PnlWznmTblRef1NDialog.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NQuerymod) this.$refs.PnlWznmTblRef1NQuerymod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFct1NTablecol) this.$refs.PnlWznmTblFct1NTablecol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NRtblock) this.$refs.PnlWznmTblRef1NRtblock.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmTblHk1NVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmTblRef1NPanel.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefPst1NQuerymod) this.$refs.PnlWznmTblPst1NQuerymod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNVector) this.$refs.PnlWznmTblMNVector.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNQuery) this.$refs.PnlWznmTblMNQuery.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmTblRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmTblRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmTblDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefALoadfct) this.$refs.PnlWznmTblALoadfct.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmTblATitle.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NImpexp) this.$refs.PnlWznmTbl1NImpexp.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NStub) this.$refs.PnlWznmTbl1NStub.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSubset) this.$refs.PnlWznmTbl1NSubset.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefTbl1NTablecol) this.$refs.PnlWznmTblTbl1NTablecol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFr1NRelation) this.$refs.PnlWznmTblFr1NRelation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefTo1NRelation) this.$refs.PnlWznmTblTo1NRelation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NCheck) this.$refs.PnlWznmTbl1NCheck.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSrc1NFeed) this.$refs.PnlWznmTblSrc1NFeed.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NCall) this.$refs.PnlWznmTblRef1NCall.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NDialog) this.$refs.PnlWznmTblRef1NDialog.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NQuerymod) this.$refs.PnlWznmTblRef1NQuerymod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFct1NTablecol) this.$refs.PnlWznmTblFct1NTablecol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NRtblock) this.$refs.PnlWznmTblRef1NRtblock.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefHk1NVector) this.$refs.PnlWznmTblHk1NVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmTblRef1NPanel.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefPst1NQuerymod) this.$refs.PnlWznmTblPst1NQuerymod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNVector) this.$refs.PnlWznmTblMNVector.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNQuery) this.$refs.PnlWznmTblMNQuery.handleUpdate(obj);
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
