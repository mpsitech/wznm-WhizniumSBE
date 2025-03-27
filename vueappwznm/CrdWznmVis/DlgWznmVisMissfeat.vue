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
				v-model="continf.CmfTxtPrg"
				:label="tag.CptCmfPrg"
			/>

			<v-divider/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('', 'CmfButRunClick')"
						:disabled="!statshr.CmfButRunActive"
						class="my-1"
						color="primary"
					>
						{{tag.CmfButRun}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('', 'CmfButStoClick')"
						:disabled="!statshr.CmfButStoActive"
						class="my-1"
						color="primary"
					>
						{{tag.CmfButSto}}
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
		name: 'DlgWznmVisMissfeat',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVisMissfeat.mounted() with scrJref = " + this.scrJref);

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
				var srefIxVDo = "srefIxVDo";
				if (ditshort != "") srefIxVDo += ditshort.charAt(0).toUpperCase() + ditshort.slice(1);

				const dpchapp = {
					"DpchAppDlgWznmVisMissfeatDo": {
						"scrJref": this.scrJref,
						[srefIxVDo]: ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVisMissfeat"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVisMissfeatData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVisMissfeatData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfDlgWznmVisMissfeat) this.continf = dpcheng.ContInfDlgWznmVisMissfeat;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVisMissfeat) this.statapp = dpcheng.StatAppDlgWznmVisMissfeat;
				if (dpcheng.StatShrDlgWznmVisMissfeat) this.statshr = dpcheng.StatShrDlgWznmVisMissfeat;
				if (dpcheng.TagDlgWznmVisMissfeat) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisMissfeat);
					this.tag = dpcheng.TagDlgWznmVisMissfeat;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVisMissfeatData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVisMissfeatData") this.mergeDpchEngData(obj.dpcheng);
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
