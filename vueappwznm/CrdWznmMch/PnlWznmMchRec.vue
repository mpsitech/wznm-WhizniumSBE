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
					<PnlWznmMchDetail
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmMchDetail"
						:scrJref=statshr.scrJrefDetail
					/>
				</v-col>
			</v-row>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmMchAMakefile
						v-on:request="handleRequest"
						ref="PnlWznmMchAMakefile"
						:scrJref=statshr.scrJrefAMakefile
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmMchAPar
						v-on:request="handleRequest"
						ref="PnlWznmMchAPar"
						:scrJref=statshr.scrJrefAPar
					/>
				</v-col>
			</v-row>
			<v-divider/>
			<v-row>
				<v-col cols="12" md="6">
					<PnlWznmMch1NRelease
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmMch1NRelease"
						:scrJref=statshr.scrJref1NRelease
					/>
				</v-col>
				<v-col cols="12" md="6">
					<PnlWznmMchSup1NMachine
						v-on:crdopen="handleCrdopen"
						v-on:request="handleRequest"
						ref="PnlWznmMchSup1NMachine"
						:scrJref=statshr.scrJrefSup1NMachine
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
	import PnlWznmMchDetail from './PnlWznmMchDetail';
	import PnlWznmMchAMakefile from './PnlWznmMchAMakefile';
	import PnlWznmMchAPar from './PnlWznmMchAPar';
	import PnlWznmMch1NRelease from './PnlWznmMch1NRelease';
	import PnlWznmMchSup1NMachine from './PnlWznmMchSup1NMachine';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmMchRec',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWznmMchDetail,
			PnlWznmMchAMakefile,
			PnlWznmMchAPar,
			PnlWznmMch1NRelease,
			PnlWznmMchSup1NMachine
			/*
			*/
		},

		mounted() {
			//console.log("PnlWznmMchRec.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmMchRecDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				if (dpcheng.ContInfWznmMchRec) this.continf = dpcheng.ContInfWznmMchRec;
				if (dpcheng.StatAppWznmMchRec) this.statapp = dpcheng.StatAppWznmMchRec;
				if (dpcheng.StatShrWznmMchRec) this.statshr = dpcheng.StatShrWznmMchRec;
				if (dpcheng.TagWznmMchRec) {
					Wznm.unescapeBlock(dpcheng.TagWznmMchRec);
					this.tag = dpcheng.TagWznmMchRec;
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
						if (obj.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmMchDetail.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAMakefile) this.$refs.PnlWznmMchAMakefile.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWznmMchAPar.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWznmMch1NRelease.handleReply(obj);
						else if (obj.scrJref == this.statshr.scrJrefSup1NMachine) this.$refs.PnlWznmMchSup1NMachine.handleReply(obj);
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
				if (srefIxWznmVDpch == "DpchEngWznmMchRecData") this.mergeDpchEngData(dpcheng);
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWznmVDpch == "DpchEngWznmMchRecData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					if (this.statshr.srefIxWznmVExpstate == "regd") {
						processed = true;

						/*
						*/
						if (obj.dpcheng.scrJref == this.statshr.scrJrefDetail) this.$refs.PnlWznmMchDetail.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAMakefile) this.$refs.PnlWznmMchAMakefile.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefAPar) this.$refs.PnlWznmMchAPar.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJref1NRelease) this.$refs.PnlWznmMch1NRelease.handleUpdate(obj);
						else if (obj.dpcheng.scrJref == this.statshr.scrJrefSup1NMachine) this.$refs.PnlWznmMchSup1NMachine.handleUpdate(obj);
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
