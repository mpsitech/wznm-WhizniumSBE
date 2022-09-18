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
					<PnlWznmQryDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmQryDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmQryAOrder
						v-on:request="handleRequest"
						ref="PnlWznmQryAOrder"
						:scrJref=statshr.scrJrefAOrder
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmQryAClause
						v-on:request="handleRequest"
						ref="PnlWznmQryAClause"
						:scrJref=statshr.scrJrefAClause
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmQrySup1NQuery
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmQrySup1NQuery"
						:scrJref=statshr.scrJrefSup1NQuery
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmQry1NQuerymod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmQry1NQuerymod"
						:scrJref=statshr.scrJref1NQuerymod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmQryQry1NQuerycol
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmQryQry1NQuerycol"
						:scrJref=statshr.scrJrefQry1NQuerycol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmQryMNTable
						v-on:request="handleRequest"
						ref="PnlWznmQryMNTable"
						:scrJref=statshr.scrJrefMNTable
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmQryMNPanel
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmQryMNPanel"
						:scrJref=statshr.scrJrefMNPanel
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmQryMNDialog
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmQryMNDialog"
						:scrJref=statshr.scrJrefMNDialog
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
	import PnlWznmQryDetail from './PnlWznmQryDetail';
	import PnlWznmQryAOrder from './PnlWznmQryAOrder';
	import PnlWznmQryAClause from './PnlWznmQryAClause';
	import PnlWznmQrySup1NQuery from './PnlWznmQrySup1NQuery';
	import PnlWznmQry1NQuerymod from './PnlWznmQry1NQuerymod';
	import PnlWznmQryQry1NQuerycol from './PnlWznmQryQry1NQuerycol';
	import PnlWznmQryMNTable from './PnlWznmQryMNTable';
	import PnlWznmQryMNPanel from './PnlWznmQryMNPanel';
	import PnlWznmQryMNDialog from './PnlWznmQryMNDialog';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmQryRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmQryDetail,
			PnlWznmQryAOrder,
			PnlWznmQryAClause,
			PnlWznmQrySup1NQuery,
			PnlWznmQry1NQuerymod,
			PnlWznmQryQry1NQuerycol,
			PnlWznmQryMNTable,
			PnlWznmQryMNPanel,
			PnlWznmQryMNDialog
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmQryRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmQryRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmQryRec) this.continf = dpcheng.ContInfWznmQryRec;
				if (dpcheng.StatAppWznmQryRec) this.statapp = dpcheng.StatAppWznmQryRec;
				if (dpcheng.StatShrWznmQryRec) this.statshr = dpcheng.StatShrWznmQryRec;
				if (dpcheng.TagWznmQryRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmQryRec);
					this.tag = dpcheng.TagWznmQryRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmQryDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAOrder) this.$refs.PnlWznmQryAOrder.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAClause) this.$refs.PnlWznmQryAClause.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NQuery) this.$refs.PnlWznmQrySup1NQuery.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NQuerymod) this.$refs.PnlWznmQry1NQuerymod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefQry1NQuerycol) this.$refs.PnlWznmQryQry1NQuerycol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNTable) this.$refs.PnlWznmQryMNTable.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNPanel) this.$refs.PnlWznmQryMNPanel.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNDialog) this.$refs.PnlWznmQryMNDialog.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmQryRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmQryRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmQryDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAOrder) this.$refs.PnlWznmQryAOrder.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAClause) this.$refs.PnlWznmQryAClause.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NQuery) this.$refs.PnlWznmQrySup1NQuery.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NQuerymod) this.$refs.PnlWznmQry1NQuerymod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefQry1NQuerycol) this.$refs.PnlWznmQryQry1NQuerycol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNTable) this.$refs.PnlWznmQryMNTable.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNPanel) this.$refs.PnlWznmQryMNPanel.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNDialog) this.$refs.PnlWznmQryMNDialog.handleUpdate(obj);
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
