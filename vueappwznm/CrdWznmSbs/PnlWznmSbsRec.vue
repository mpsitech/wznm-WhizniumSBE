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
					<PnlWznmSbsDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbsDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmSbsATitle
						v-on:request="handleRequest"
						ref="PnlWznmSbsATitle"
						:scrJref=statshr.scrJrefATitle
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmSbsTos1NRelation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbsTos1NRelation"
						:scrJref=statshr.scrJrefTos1NRelation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSbs1NStub
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbs1NStub"
						:scrJref=statshr.scrJref1NStub
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSbs1NTablecol
						v-on:request="handleRequest"
						ref="PnlWznmSbs1NTablecol"
						:scrJref=statshr.scrJref1NTablecol
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSbsFrs1NRelation
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbsFrs1NRelation"
						:scrJref=statshr.scrJrefFrs1NRelation
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSbsPst1NQuerymod
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbsPst1NQuerymod"
						:scrJref=statshr.scrJrefPst1NQuerymod
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSbsAsbMNSubset
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbsAsbMNSubset"
						:scrJref=statshr.scrJrefAsbMNSubset
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmSbsBsbMNSubset
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmSbsBsbMNSubset"
						:scrJref=statshr.scrJrefBsbMNSubset
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
	import PnlWznmSbsDetail from './PnlWznmSbsDetail';
	import PnlWznmSbsATitle from './PnlWznmSbsATitle';
	import PnlWznmSbsTos1NRelation from './PnlWznmSbsTos1NRelation';
	import PnlWznmSbs1NStub from './PnlWznmSbs1NStub';
	import PnlWznmSbs1NTablecol from './PnlWznmSbs1NTablecol';
	import PnlWznmSbsFrs1NRelation from './PnlWznmSbsFrs1NRelation';
	import PnlWznmSbsPst1NQuerymod from './PnlWznmSbsPst1NQuerymod';
	import PnlWznmSbsAsbMNSubset from './PnlWznmSbsAsbMNSubset';
	import PnlWznmSbsBsbMNSubset from './PnlWznmSbsBsbMNSubset';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmSbsRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmSbsDetail,
			PnlWznmSbsATitle,
			PnlWznmSbsTos1NRelation,
			PnlWznmSbs1NStub,
			PnlWznmSbs1NTablecol,
			PnlWznmSbsFrs1NRelation,
			PnlWznmSbsPst1NQuerymod,
			PnlWznmSbsAsbMNSubset,
			PnlWznmSbsBsbMNSubset
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmSbsRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmSbsRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmSbsRec) this.continf = dpcheng.ContInfWznmSbsRec;
				if (dpcheng.StatAppWznmSbsRec) this.statapp = dpcheng.StatAppWznmSbsRec;
				if (dpcheng.StatShrWznmSbsRec) this.statshr = dpcheng.StatShrWznmSbsRec;
				if (dpcheng.TagWznmSbsRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmSbsRec);
					this.tag = dpcheng.TagWznmSbsRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmSbsDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmSbsATitle.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefTos1NRelation) this.$refs.PnlWznmSbsTos1NRelation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NStub) this.$refs.PnlWznmSbs1NStub.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NTablecol) this.$refs.PnlWznmSbs1NTablecol.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefFrs1NRelation) this.$refs.PnlWznmSbsFrs1NRelation.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefPst1NQuerymod) this.$refs.PnlWznmSbsPst1NQuerymod.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAsbMNSubset) this.$refs.PnlWznmSbsAsbMNSubset.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefBsbMNSubset) this.$refs.PnlWznmSbsBsbMNSubset.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmSbsRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmSbsRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmSbsDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefATitle) this.$refs.PnlWznmSbsATitle.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefTos1NRelation) this.$refs.PnlWznmSbsTos1NRelation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NStub) this.$refs.PnlWznmSbs1NStub.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NTablecol) this.$refs.PnlWznmSbs1NTablecol.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefFrs1NRelation) this.$refs.PnlWznmSbsFrs1NRelation.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefPst1NQuerymod) this.$refs.PnlWznmSbsPst1NQuerymod.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAsbMNSubset) this.$refs.PnlWznmSbsAsbMNSubset.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefBsbMNSubset) this.$refs.PnlWznmSbsBsbMNSubset.handleUpdate(obj);
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
