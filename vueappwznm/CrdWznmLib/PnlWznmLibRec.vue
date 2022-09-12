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
					<PnlWznmLibDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmLibDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmLibAPkglist
						v-on:request="handleRequest"
						ref="PnlWznmLibAPkglist"
						:scrJref=statshr.scrJrefAPkglist
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmLibAMakefile
						v-on:request="handleRequest"
						ref="PnlWznmLibAMakefile"
						:scrJref=statshr.scrJrefAMakefile
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmLibRef1NFile
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmLibRef1NFile"
						:scrJref=statshr.scrJrefRef1NFile
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmLibMNOppack
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmLibMNOppack"
						:scrJref=statshr.scrJrefMNOppack
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmLibMNComponent
						v-on:request="handleRequest"
						ref="PnlWznmLibMNComponent"
						:scrJref=statshr.scrJrefMNComponent
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
	import PnlWznmLibDetail from './PnlWznmLibDetail';
	import PnlWznmLibAPkglist from './PnlWznmLibAPkglist';
	import PnlWznmLibAMakefile from './PnlWznmLibAMakefile';
	import PnlWznmLibRef1NFile from './PnlWznmLibRef1NFile';
	import PnlWznmLibMNOppack from './PnlWznmLibMNOppack';
	import PnlWznmLibMNComponent from './PnlWznmLibMNComponent';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmLibRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmLibDetail,
			PnlWznmLibAPkglist,
			PnlWznmLibAMakefile,
			PnlWznmLibRef1NFile,
			PnlWznmLibMNOppack,
			PnlWznmLibMNComponent
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmLibRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmLibRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmLibRec) this.continf = dpcheng.ContInfWznmLibRec;
				if (dpcheng.StatAppWznmLibRec) this.statapp = dpcheng.StatAppWznmLibRec;
				if (dpcheng.StatShrWznmLibRec) this.statshr = dpcheng.StatShrWznmLibRec;
				if (dpcheng.TagWznmLibRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmLibRec);
					this.tag = dpcheng.TagWznmLibRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmLibDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPkglist) this.$refs.PnlWznmLibAPkglist.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAMakefile) this.$refs.PnlWznmLibAMakefile.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWznmLibRef1NFile.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNOppack) this.$refs.PnlWznmLibMNOppack.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefMNComponent) this.$refs.PnlWznmLibMNComponent.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmLibRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmLibRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmLibDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPkglist) this.$refs.PnlWznmLibAPkglist.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAMakefile) this.$refs.PnlWznmLibAMakefile.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefRef1NFile) this.$refs.PnlWznmLibRef1NFile.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNOppack) this.$refs.PnlWznmLibMNOppack.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefMNComponent) this.$refs.PnlWznmLibMNComponent.handleUpdate(obj);
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
