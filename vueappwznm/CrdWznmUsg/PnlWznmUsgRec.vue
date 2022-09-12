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
					<PnlWznmUsgDetail
						v-on:request="handleRequest"
						ref="PnlWznmUsgDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmUsgAAccess
						v-on:request="handleRequest"
						ref="PnlWznmUsgAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmUsgMNUser
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmUsgMNUser"
						:scrJref=statshr.scrJrefMNUser
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
	import PnlWznmUsgDetail from './PnlWznmUsgDetail';
	import PnlWznmUsgAAccess from './PnlWznmUsgAAccess';
	import PnlWznmUsgMNUser from './PnlWznmUsgMNUser';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmUsgRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmUsgDetail,
			PnlWznmUsgAAccess,
			PnlWznmUsgMNUser
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmUsgRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmUsgRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmUsgRec) this.continf = dpcheng.ContInfWznmUsgRec;
				if (dpcheng.StatAppWznmUsgRec) this.statapp = dpcheng.StatAppWznmUsgRec;
				if (dpcheng.StatShrWznmUsgRec) this.statshr = dpcheng.StatShrWznmUsgRec;
				if (dpcheng.TagWznmUsgRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmUsgRec);
					this.tag = dpcheng.TagWznmUsgRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmUsgDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWznmUsgAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlWznmUsgMNUser.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmUsgRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmUsgRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmUsgDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWznmUsgAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUser) this.$refs.PnlWznmUsgMNUser.handleUpdate(obj);
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
