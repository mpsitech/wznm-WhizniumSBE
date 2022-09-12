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
				v-model="continf.DetTxtSte"
				:label="tag.CptDetSte"
			/>

			<v-row class="my-1">
				<v-col>
					<v-btn
						v-on:click="handleButClick('DetButDelClick')"
						class="my-1"
						color="primary"
					>
						{{tag.DetButDel}}
					</v-btn>
					&#160;
					<v-btn
						v-on:click="handleButClick('DetButGenClick')"
						class="my-1"
						color="primary"
					>
						{{tag.DetButGen}}
					</v-btn>
				</v-col>
			</v-row>

			<v-divider/>

			<v-btn
				download
				:href="hrefDld"
				:disabled="!statshr.DldActive"
				class="my-1"
				color="primary"
			>
				{{tag.Dld}}
			</v-btn>
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
		name: 'DlgWznmUsrMngkeypair',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmUsrMngkeypair.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmUsrMngkeypairDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmUsrMngkeypairDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmUsrMngkeypair"] = this.contiac;
				/*
				*/
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmUsrMngkeypairData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmUsrMngkeypairData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContInfDlgWznmUsrMngkeypair) this.continf = dpcheng.ContInfDlgWznmUsrMngkeypair;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmUsrMngkeypair) this.statapp = dpcheng.StatAppDlgWznmUsrMngkeypair;
				if (dpcheng.StatShrDlgWznmUsrMngkeypair) this.statshr = dpcheng.StatShrDlgWznmUsrMngkeypair;
				if (dpcheng.TagDlgWznmUsrMngkeypair) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUsrMngkeypair);
					this.tag = dpcheng.TagDlgWznmUsrMngkeypair;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmUsrMngkeypairData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmUsrMngkeypairData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			hrefDld: function() {
				return window.location.protocol + '//' + Wznm.hostname() + ':' + Wznm.appsrvport() + '/download/' + this.scrJref;
			},

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
