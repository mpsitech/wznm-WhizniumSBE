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
							<v-file-input
								outlined
								show-size
								:label="tagsrc.Cpt"
								v-model="contappsrc.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('src')"
								:disabled="contappsrc.file == null"
								color="primary"
							>
								{{tagsrc.Uld}}
							</v-btn>
						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								outlined
								show-size
								:label="tagtrg.Cpt"
								v-model="contapptrg.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('trg')"
								:disabled="contapptrg.file == null"
								color="primary"
							>
								{{tagtrg.Uld}}
							</v-btn>
						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-text-field
								class="my-1"
								readonly
								outlined
								v-model="continfmrg.TxtPrg"
								:label="tagmrg.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('mrg', 'ButRunClick')"
										:disabled="!statshrmrg.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagmrg.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('mrg', 'ButStoClick')"
										:disabled="!statshrmrg.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagmrg.ButSto}}
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
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-btn
								download
								:href="hrefDld"
								target="_blank"
								:disabled="!statshrres.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagres.Dld}}
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
		name: 'DlgWznmUtlMrgip',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmUtlMrgip.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmUtlMrgipDo": {
						"scrJref": this.scrJref,
						[srefIxVDo]: ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmUtlMrgip"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacsrc") != -1) dpchapp["ContIacDlgWznmUtlMrgipSrc"] = this.contiacsrc;
				if (mask.indexOf("contiactrg") != -1) dpchapp["ContIacDlgWznmUtlMrgipTrg"] = this.contiactrg;
				if (mask.indexOf("contiacmrg") != -1) dpchapp["ContIacDlgWznmUtlMrgipMrg"] = this.contiacmrg;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmUtlMrgipLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacres") != -1) dpchapp["ContIacDlgWznmUtlMrgipRes"] = this.contiacres;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmUtlMrgipData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmUtlMrgipData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmUtlMrgip) this.contiac = dpcheng.ContIacDlgWznmUtlMrgip;
				if (dpcheng.ContInfDlgWznmUtlMrgip) this.continf = dpcheng.ContInfDlgWznmUtlMrgip;
				if (dpcheng.ContInfDlgWznmUtlMrgipLfi) this.continflfi = dpcheng.ContInfDlgWznmUtlMrgipLfi;
				if (dpcheng.ContInfDlgWznmUtlMrgipMrg) this.continfmrg = dpcheng.ContInfDlgWznmUtlMrgipMrg;
				if (dpcheng.ContInfDlgWznmUtlMrgipRes) this.continfres = dpcheng.ContInfDlgWznmUtlMrgipRes;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmUtlMrgip) this.statapp = dpcheng.StatAppDlgWznmUtlMrgip;
				if (dpcheng.StatShrDlgWznmUtlMrgip) this.statshr = dpcheng.StatShrDlgWznmUtlMrgip;
				if (dpcheng.StatShrDlgWznmUtlMrgipLfi) this.statshrlfi = dpcheng.StatShrDlgWznmUtlMrgipLfi;
				if (dpcheng.StatShrDlgWznmUtlMrgipMrg) this.statshrmrg = dpcheng.StatShrDlgWznmUtlMrgipMrg;
				if (dpcheng.StatShrDlgWznmUtlMrgipRes) this.statshrres = dpcheng.StatShrDlgWznmUtlMrgipRes;
				if (dpcheng.StatShrDlgWznmUtlMrgipSrc) this.statshrsrc = dpcheng.StatShrDlgWznmUtlMrgipSrc;
				if (dpcheng.StatShrDlgWznmUtlMrgipTrg) this.statshrtrg = dpcheng.StatShrDlgWznmUtlMrgipTrg;
				if (dpcheng.TagDlgWznmUtlMrgip) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlMrgip);
					this.tag = dpcheng.TagDlgWznmUtlMrgip;
				}
				if (dpcheng.TagDlgWznmUtlMrgipLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlMrgipLfi);
					this.taglfi = dpcheng.TagDlgWznmUtlMrgipLfi;
				}
				if (dpcheng.TagDlgWznmUtlMrgipMrg) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlMrgipMrg);
					this.tagmrg = dpcheng.TagDlgWznmUtlMrgipMrg;
				}
				if (dpcheng.TagDlgWznmUtlMrgipRes) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlMrgipRes);
					this.tagres = dpcheng.TagDlgWznmUtlMrgipRes;
				}
				if (dpcheng.TagDlgWznmUtlMrgipSrc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlMrgipSrc);
					this.tagsrc = dpcheng.TagDlgWznmUtlMrgipSrc;
				}
				if (dpcheng.TagDlgWznmUtlMrgipTrg) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlMrgipTrg);
					this.tagtrg = dpcheng.TagDlgWznmUtlMrgipTrg;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmUtlMrgipData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmUtlMrgipData") this.mergeDpchEngData(obj.dpcheng);
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

			continflfi: null,

			continfmrg: null,

			continfres: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrlfi: null,

			statshrmrg: null,

			statshrres: null,

			statshrsrc: null,

			statshrtrg: null,

			tag: null,

			taglfi: null,

			tagmrg: null,

			tagres: null,

			tagsrc: null,

			tagtrg: null,

			contappsrc: {
				file: null,

			},

			contapptrg: {
				file: null,

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
