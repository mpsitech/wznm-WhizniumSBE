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
			<v-tabs
				v-model="numFDse"
				align-with-title
			>
				<v-tabs-slider></v-tabs-slider>
				<v-tab v-for="{num, tit1} in feedFDse" :key="num">{{tit1}}</v-tab>
			</v-tabs>
		</v-card-title>
		<v-card-text>
			<v-tabs-items v-model="numFDse">
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-text-field
								class="my-1"
								readonly
								outlined
								v-model="continfwri.TxtPrg"
								:label="tagwri.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('wri', 'ButRunClick')"
										:disabled="!statshrwri.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagwri.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('wri', 'ButStoClick')"
										:disabled="!statshrwri.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagwri.ButSto}}
									</v-btn>
								</v-col>
							</v-row>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-btn
								download
								:href="hrefDld"
								target="_blank"
								:disabled="!statshrfia.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagfia.Dld}}
							</v-btn>
						</v-card-text>
					</v-card>
				</v-tab-item>
			</v-tabs-items>
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
		name: 'DlgWznmVerWrinimdl',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerWrinimdl.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVerWrinimdlDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerWrinimdl"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacwri") != -1) dpchapp["ContIacDlgWznmVerWrinimdlWri"] = this.contiacwri;
				if (mask.indexOf("contiacfia") != -1) dpchapp["ContIacDlgWznmVerWrinimdlFia"] = this.contiacfia;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerWrinimdlData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerWrinimdlData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVerWrinimdl) this.contiac = dpcheng.ContIacDlgWznmVerWrinimdl;
				if (dpcheng.ContInfDlgWznmVerWrinimdl) this.continf = dpcheng.ContInfDlgWznmVerWrinimdl;
				if (dpcheng.ContInfDlgWznmVerWrinimdlFia) this.continffia = dpcheng.ContInfDlgWznmVerWrinimdlFia;
				if (dpcheng.ContInfDlgWznmVerWrinimdlWri) this.continfwri = dpcheng.ContInfDlgWznmVerWrinimdlWri;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerWrinimdl) this.statapp = dpcheng.StatAppDlgWznmVerWrinimdl;
				if (dpcheng.StatShrDlgWznmVerWrinimdl) this.statshr = dpcheng.StatShrDlgWznmVerWrinimdl;
				if (dpcheng.StatShrDlgWznmVerWrinimdlFia) this.statshrfia = dpcheng.StatShrDlgWznmVerWrinimdlFia;
				if (dpcheng.StatShrDlgWznmVerWrinimdlWri) this.statshrwri = dpcheng.StatShrDlgWznmVerWrinimdlWri;
				if (dpcheng.TagDlgWznmVerWrinimdl) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerWrinimdl);
					this.tag = dpcheng.TagDlgWznmVerWrinimdl;
				}
				if (dpcheng.TagDlgWznmVerWrinimdlFia) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerWrinimdlFia);
					this.tagfia = dpcheng.TagDlgWznmVerWrinimdlFia;
				}
				if (dpcheng.TagDlgWznmVerWrinimdlWri) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerWrinimdlWri);
					this.tagwri = dpcheng.TagDlgWznmVerWrinimdlWri;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerWrinimdlData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerWrinimdlData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			hrefDld: function() {
				return window.location.protocol + '//' + Wznm.hostname() + ':' + Wznm.appsrvport() + '/download/' + this.scrJref;
			},

			numFDse: {
				get() {
					return this.contiac.numFDse - 1;
				},
				set(sel) {
					if (sel == null) this.contiac.numFDse = 1;
					else this.contiac.numFDse = sel + 1;

					return sel;
				}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			continffia: null,

			continfwri: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrfia: null,

			statshrwri: null,

			tag: null,

			tagfia: null,

			tagwri: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
