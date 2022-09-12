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
							<v-text-field
								class="my-1"
								readonly
								outlined
								v-model="continfext.TxtPrg"
								:label="tagext.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('ext', 'ButRunClick')"
										:disabled="!statshrext.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagext.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('ext', 'ButStoClick')"
										:disabled="!statshrext.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagext.ButSto}}
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
		name: 'DlgWznmUtlExtrip',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmUtlExtrip.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmUtlExtripDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmUtlExtripDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmUtlExtrip"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacsrc") != -1) dpchapp["ContIacDlgWznmUtlExtripSrc"] = this.contiacsrc;
				if (mask.indexOf("contiacext") != -1) dpchapp["ContIacDlgWznmUtlExtripExt"] = this.contiacext;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmUtlExtripLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacres") != -1) dpchapp["ContIacDlgWznmUtlExtripRes"] = this.contiacres;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmUtlExtripData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmUtlExtripData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmUtlExtrip) this.contiac = dpcheng.ContIacDlgWznmUtlExtrip;
				if (dpcheng.ContInfDlgWznmUtlExtrip) this.continf = dpcheng.ContInfDlgWznmUtlExtrip;
				if (dpcheng.ContInfDlgWznmUtlExtripExt) this.continfext = dpcheng.ContInfDlgWznmUtlExtripExt;
				if (dpcheng.ContInfDlgWznmUtlExtripLfi) this.continflfi = dpcheng.ContInfDlgWznmUtlExtripLfi;
				if (dpcheng.ContInfDlgWznmUtlExtripRes) this.continfres = dpcheng.ContInfDlgWznmUtlExtripRes;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmUtlExtrip) this.statapp = dpcheng.StatAppDlgWznmUtlExtrip;
				if (dpcheng.StatShrDlgWznmUtlExtrip) this.statshr = dpcheng.StatShrDlgWznmUtlExtrip;
				if (dpcheng.StatShrDlgWznmUtlExtripExt) this.statshrext = dpcheng.StatShrDlgWznmUtlExtripExt;
				if (dpcheng.StatShrDlgWznmUtlExtripLfi) this.statshrlfi = dpcheng.StatShrDlgWznmUtlExtripLfi;
				if (dpcheng.StatShrDlgWznmUtlExtripRes) this.statshrres = dpcheng.StatShrDlgWznmUtlExtripRes;
				if (dpcheng.StatShrDlgWznmUtlExtripSrc) this.statshrsrc = dpcheng.StatShrDlgWznmUtlExtripSrc;
				if (dpcheng.TagDlgWznmUtlExtrip) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlExtrip);
					this.tag = dpcheng.TagDlgWznmUtlExtrip;
				}
				if (dpcheng.TagDlgWznmUtlExtripExt) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlExtripExt);
					this.tagext = dpcheng.TagDlgWznmUtlExtripExt;
				}
				if (dpcheng.TagDlgWznmUtlExtripLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlExtripLfi);
					this.taglfi = dpcheng.TagDlgWznmUtlExtripLfi;
				}
				if (dpcheng.TagDlgWznmUtlExtripRes) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlExtripRes);
					this.tagres = dpcheng.TagDlgWznmUtlExtripRes;
				}
				if (dpcheng.TagDlgWznmUtlExtripSrc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmUtlExtripSrc);
					this.tagsrc = dpcheng.TagDlgWznmUtlExtripSrc;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmUtlExtripData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmUtlExtripData") this.mergeDpchEngData(obj.dpcheng);
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

			continfext: null,

			continflfi: null,

			continfres: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrext: null,

			statshrlfi: null,

			statshrres: null,

			statshrsrc: null,

			tag: null,

			tagext: null,

			taglfi: null,

			tagres: null,

			tagsrc: null,

			contappsrc: {
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
