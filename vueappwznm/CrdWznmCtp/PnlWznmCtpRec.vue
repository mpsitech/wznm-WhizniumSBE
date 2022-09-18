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
					<PnlWznmCtpDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCtpDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmCtpKParKey
						v-on:request="handleRequest"
						ref="PnlWznmCtpKParKey"
						:scrJref=statshr.scrJrefKParKey
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCtpKKey
						v-on:request="handleRequest"
						ref="PnlWznmCtpKKey"
						:scrJref=statshr.scrJrefKKey
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCtpAPar
						v-on:request="handleRequest"
						ref="PnlWznmCtpAPar"
						:scrJref=statshr.scrJrefAPar
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmCtp1NTag
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCtp1NTag"
						:scrJref=statshr.scrJref1NTag
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmCtpTpl1NCapability
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmCtpTpl1NCapability"
						:scrJref=statshr.scrJrefTpl1NCapability
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
	import PnlWznmCtpDetail from './PnlWznmCtpDetail';
	import PnlWznmCtpKParKey from './PnlWznmCtpKParKey';
	import PnlWznmCtpKKey from './PnlWznmCtpKKey';
	import PnlWznmCtpAPar from './PnlWznmCtpAPar';
	import PnlWznmCtp1NTag from './PnlWznmCtp1NTag';
	import PnlWznmCtpTpl1NCapability from './PnlWznmCtpTpl1NCapability';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmCtpRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmCtpDetail,
			PnlWznmCtpKParKey,
			PnlWznmCtpKKey,
			PnlWznmCtpAPar,
			PnlWznmCtp1NTag,
			PnlWznmCtpTpl1NCapability
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmCtpRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmCtpRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmCtpRec) this.continf = dpcheng.ContInfWznmCtpRec;
				if (dpcheng.StatAppWznmCtpRec) this.statapp = dpcheng.StatAppWznmCtpRec;
				if (dpcheng.StatShrWznmCtpRec) this.statshr = dpcheng.StatShrWznmCtpRec;
				if (dpcheng.TagWznmCtpRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmCtpRec);
					this.tag = dpcheng.TagWznmCtpRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCtpDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefKParKey) this.$refs.PnlWznmCtpKParKey.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefKKey) this.$refs.PnlWznmCtpKKey.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWznmCtpAPar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NTag) this.$refs.PnlWznmCtp1NTag.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefTpl1NCapability) this.$refs.PnlWznmCtpTpl1NCapability.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmCtpRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmCtpRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmCtpDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefKParKey) this.$refs.PnlWznmCtpKParKey.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefKKey) this.$refs.PnlWznmCtpKKey.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWznmCtpAPar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NTag) this.$refs.PnlWznmCtp1NTag.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefTpl1NCapability) this.$refs.PnlWznmCtpTpl1NCapability.handleUpdate(obj);
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
