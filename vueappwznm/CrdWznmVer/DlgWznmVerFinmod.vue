<template>
	<v-card v-if="initdone" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="4">
					<div>
						<span>{{tag.Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="8" align="end"/>
			</v-row>
		</v-card-title>
		<v-card-text>
			<v-text-field
				class="my-1"
				readonly
				outlined
				v-model="continf.FnmTxtPrg"
				:label="tag.CptFnmPrg"
			/>

			<v-divider/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('FnmButRunClick')"
						:disabled="!statshr.FnmButRunActive"
						class="my-1"
						color="primary"
					>
						{{tag.FnmButRun}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('FnmButStoClick')"
						:disabled="!statshr.FnmButStoActive"
						class="my-1"
						color="primary"
					>
						{{tag.FnmButSto}}
					</v-btn>
				</v-col>
			</v-row>

		</v-card-text>
		<v-divider/>
		<v-card-actions>
			<v-spacer/>
			<v-btn class="primary"
				v-on:click="handleButClick('', 'ButDneClick')"
			>
				{{tag.ButDne}}
			</v-btn>
		</v-card-actions>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'DlgWznmVerFinmod',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerFinmod.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWznmInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit('request', {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			handleButClick: function(ditshort, ctlsref) {
				var dpchapp = {
					"DpchAppDlgWznmVerFinmodDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmVerFinmodDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerFinmod"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerFinmodData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerFinmodData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfDlgWznmVerFinmod) this.continf = dpcheng.ContInfDlgWznmVerFinmod;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerFinmod) this.statapp = dpcheng.StatAppDlgWznmVerFinmod;
				if (dpcheng.StatShrDlgWznmVerFinmod) this.statshr = dpcheng.StatShrDlgWznmVerFinmod;
				if (dpcheng.TagDlgWznmVerFinmod) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerFinmod);
					this.tag = dpcheng.TagDlgWznmVerFinmod;
				}
				/*
				*/
			},

			handleReply: function(obj) {
				if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);
				else if (obj.then == "handleDpchAppDataDoReply") this.handleDpchAppDataDoReply(obj.srefIxWznmVDpch, obj.dpcheng);
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleDpchAppDataDoReply: function(srefIxWznmVDpch, dpcheng) {
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerFinmodData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerFinmodData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

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
