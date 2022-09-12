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
					<PnlWznmUsrDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmUsrDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmUsrAAccess
						v-on:request="handleRequest"
						ref="PnlWznmUsrAAccess"
						:scrJref=statshr.scrJrefAAccess
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmUsr1NSession
						v-on:request="handleRequest"
						ref="PnlWznmUsr1NSession"
						:scrJref=statshr.scrJref1NSession
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmUsrMNUsergroup
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmUsrMNUsergroup"
						:scrJref=statshr.scrJrefMNUsergroup
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
	import PnlWznmUsrDetail from './PnlWznmUsrDetail';
	import PnlWznmUsrAAccess from './PnlWznmUsrAAccess';
	import PnlWznmUsr1NSession from './PnlWznmUsr1NSession';
	import PnlWznmUsrMNUsergroup from './PnlWznmUsrMNUsergroup';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmUsrRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmUsrDetail,
			PnlWznmUsrAAccess,
			PnlWznmUsr1NSession,
			PnlWznmUsrMNUsergroup
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmUsrRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmUsrRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmUsrRec) this.continf = dpcheng.ContInfWznmUsrRec;
				if (dpcheng.StatAppWznmUsrRec) this.statapp = dpcheng.StatAppWznmUsrRec;
				if (dpcheng.StatShrWznmUsrRec) this.statshr = dpcheng.StatShrWznmUsrRec;
				if (dpcheng.TagWznmUsrRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmUsrRec);
					this.tag = dpcheng.TagWznmUsrRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmUsrDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWznmUsrAAccess.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWznmUsr1NSession.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWznmUsrMNUsergroup.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmUsrRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmUsrRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmUsrDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAAccess) this.$refs.PnlWznmUsrAAccess.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NSession) this.$refs.PnlWznmUsr1NSession.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNUsergroup) this.$refs.PnlWznmUsrMNUsergroup.handleUpdate(obj);
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
