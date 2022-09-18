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
					<PnlWznmRelDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRelDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmRelATitle
						v-on:request="handleRequest"
						ref="PnlWznmRelATitle"
						:scrJref=statshr.scrJrefATitle
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmRel1NTablecol
						v-on:request="handleRequest"
						ref="PnlWznmRel1NTablecol"
						:scrJref=statshr.scrJref1NTablecol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmRelSup1NRelation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRelSup1NRelation"
						:scrJref=statshr.scrJrefSup1NRelation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmRelRef1NDialog
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRelRef1NDialog"
						:scrJref=statshr.scrJrefRef1NDialog
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmRelRef1NPanel
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRelRef1NPanel"
						:scrJref=statshr.scrJrefRef1NPanel
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmRelRef1NControl
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmRelRef1NControl"
						:scrJref=statshr.scrJrefRef1NControl
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
	import PnlWznmRelDetail from './PnlWznmRelDetail';
	import PnlWznmRelATitle from './PnlWznmRelATitle';
	import PnlWznmRel1NTablecol from './PnlWznmRel1NTablecol';
	import PnlWznmRelSup1NRelation from './PnlWznmRelSup1NRelation';
	import PnlWznmRelRef1NDialog from './PnlWznmRelRef1NDialog';
	import PnlWznmRelRef1NPanel from './PnlWznmRelRef1NPanel';
	import PnlWznmRelRef1NControl from './PnlWznmRelRef1NControl';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmRelRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmRelDetail,
			PnlWznmRelATitle,
			PnlWznmRel1NTablecol,
			PnlWznmRelSup1NRelation,
			PnlWznmRelRef1NDialog,
			PnlWznmRelRef1NPanel,
			PnlWznmRelRef1NControl
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmRelRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmRelRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmRelRec) this.continf = dpcheng.ContInfWznmRelRec;
				if (dpcheng.StatAppWznmRelRec) this.statapp = dpcheng.StatAppWznmRelRec;
				if (dpcheng.StatShrWznmRelRec) this.statshr = dpcheng.StatShrWznmRelRec;
				if (dpcheng.TagWznmRelRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmRelRec);
					this.tag = dpcheng.TagWznmRelRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmRelDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmRelATitle.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NTablecol) this.$refs.PnlWznmRel1NTablecol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NRelation) this.$refs.PnlWznmRelSup1NRelation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NDialog) this.$refs.PnlWznmRelRef1NDialog.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmRelRef1NPanel.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NControl) this.$refs.PnlWznmRelRef1NControl.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmRelRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmRelRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmRelDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmRelATitle.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NTablecol) this.$refs.PnlWznmRel1NTablecol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NRelation) this.$refs.PnlWznmRelSup1NRelation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NDialog) this.$refs.PnlWznmRelRef1NDialog.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmRelRef1NPanel.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NControl) this.$refs.PnlWznmRelRef1NControl.handleUpdate(obj);
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
