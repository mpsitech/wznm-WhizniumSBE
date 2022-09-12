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
					<PnlWznmMdlDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmMdlDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmMdlMdl1NCard
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmMdlMdl1NCard"
						:scrJref=statshr.scrJrefMdl1NCard
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmMdlRef1NPanel
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmMdlRef1NPanel"
						:scrJref=statshr.scrJrefRef1NPanel
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
	import PnlWznmMdlDetail from './PnlWznmMdlDetail';
	import PnlWznmMdlMdl1NCard from './PnlWznmMdlMdl1NCard';
	import PnlWznmMdlRef1NPanel from './PnlWznmMdlRef1NPanel';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmMdlRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmMdlDetail,
			PnlWznmMdlMdl1NCard,
			PnlWznmMdlRef1NPanel
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmMdlRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmMdlRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmMdlRec) this.continf = dpcheng.ContInfWznmMdlRec;
				if (dpcheng.StatAppWznmMdlRec) this.statapp = dpcheng.StatAppWznmMdlRec;
				if (dpcheng.StatShrWznmMdlRec) this.statshr = dpcheng.StatShrWznmMdlRec;
				if (dpcheng.TagWznmMdlRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmMdlRec);
					this.tag = dpcheng.TagWznmMdlRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmMdlDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMdl1NCard) this.$refs.PnlWznmMdlMdl1NCard.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmMdlRef1NPanel.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmMdlRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmMdlRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmMdlDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMdl1NCard) this.$refs.PnlWznmMdlMdl1NCard.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NPanel) this.$refs.PnlWznmMdlRef1NPanel.handleUpdate(obj);
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
