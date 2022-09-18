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
								v-model="continfgui.TxtPrg"
								:label="taggui.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('gui', 'ButRunClick')"
										:disabled="!statshrgui.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{taggui.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('gui', 'ButStoClick')"
										:disabled="!statshrgui.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{taggui.ButSto}}
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
								:disabled="!statshrlfi.DldActive"
								class="my-1"
								color="primary"
							>
								{{taglfi.Dld}}
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
		name: 'DlgWznmVerGenui',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerGenui.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVerGenuiDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerGenui"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacgui") != -1) dpchapp["ContIacDlgWznmVerGenuiGui"] = this.contiacgui;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmVerGenuiLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerGenuiData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerGenuiData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVerGenui) this.contiac = dpcheng.ContIacDlgWznmVerGenui;
				if (dpcheng.ContInfDlgWznmVerGenui) this.continf = dpcheng.ContInfDlgWznmVerGenui;
				if (dpcheng.ContInfDlgWznmVerGenuiGui) this.continfgui = dpcheng.ContInfDlgWznmVerGenuiGui;
				if (dpcheng.ContInfDlgWznmVerGenuiLfi) this.continflfi = dpcheng.ContInfDlgWznmVerGenuiLfi;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerGenui) this.statapp = dpcheng.StatAppDlgWznmVerGenui;
				if (dpcheng.StatShrDlgWznmVerGenui) this.statshr = dpcheng.StatShrDlgWznmVerGenui;
				if (dpcheng.StatShrDlgWznmVerGenuiGui) this.statshrgui = dpcheng.StatShrDlgWznmVerGenuiGui;
				if (dpcheng.StatShrDlgWznmVerGenuiLfi) this.statshrlfi = dpcheng.StatShrDlgWznmVerGenuiLfi;
				if (dpcheng.TagDlgWznmVerGenui) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerGenui);
					this.tag = dpcheng.TagDlgWznmVerGenui;
				}
				if (dpcheng.TagDlgWznmVerGenuiGui) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerGenuiGui);
					this.taggui = dpcheng.TagDlgWznmVerGenuiGui;
				}
				if (dpcheng.TagDlgWznmVerGenuiLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerGenuiLfi);
					this.taglfi = dpcheng.TagDlgWznmVerGenuiLfi;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerGenuiData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerGenuiData") this.mergeDpchEngData(obj.dpcheng);
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

			continfgui: null,

			continflfi: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrgui: null,

			statshrlfi: null,

			tag: null,

			taggui: null,

			taglfi: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
