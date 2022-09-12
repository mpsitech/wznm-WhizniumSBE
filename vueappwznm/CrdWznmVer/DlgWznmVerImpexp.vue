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
								:label="tagifi.Cpt"
								v-model="contappifi.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('ifi')"
								:disabled="contappifi.file == null"
								color="primary"
							>
								{{tagifi.Uld}}
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
								v-model="continfimp.TxtPrg"
								:label="tagimp.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('imp', 'ButRunClick')"
										:disabled="!statshrimp.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagimp.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('imp', 'ButStoClick')"
										:disabled="!statshrimp.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagimp.ButSto}}
									</v-btn>
								</v-col>
							</v-row>

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
								v-model="continfppr.TxtPrg"
								:label="tagppr.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('ppr', 'ButRunClick')"
										:disabled="!statshrppr.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagppr.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('ppr', 'ButStoClick')"
										:disabled="!statshrppr.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagppr.ButSto}}
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
		name: 'DlgWznmVerImpexp',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerImpexp.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVerImpexpDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmVerImpexpDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerImpexp"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacifi") != -1) dpchapp["ContIacDlgWznmVerImpexpIfi"] = this.contiacifi;
				if (mask.indexOf("contiacimp") != -1) dpchapp["ContIacDlgWznmVerImpexpImp"] = this.contiacimp;
				if (mask.indexOf("contiacppr") != -1) dpchapp["ContIacDlgWznmVerImpexpPpr"] = this.contiacppr;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmVerImpexpLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerImpexpData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerImpexpData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVerImpexp) this.contiac = dpcheng.ContIacDlgWznmVerImpexp;
				if (dpcheng.ContInfDlgWznmVerImpexp) this.continf = dpcheng.ContInfDlgWznmVerImpexp;
				if (dpcheng.ContInfDlgWznmVerImpexpImp) this.continfimp = dpcheng.ContInfDlgWznmVerImpexpImp;
				if (dpcheng.ContInfDlgWznmVerImpexpLfi) this.continflfi = dpcheng.ContInfDlgWznmVerImpexpLfi;
				if (dpcheng.ContInfDlgWznmVerImpexpPpr) this.continfppr = dpcheng.ContInfDlgWznmVerImpexpPpr;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerImpexp) this.statapp = dpcheng.StatAppDlgWznmVerImpexp;
				if (dpcheng.StatShrDlgWznmVerImpexp) this.statshr = dpcheng.StatShrDlgWznmVerImpexp;
				if (dpcheng.StatShrDlgWznmVerImpexpIfi) this.statshrifi = dpcheng.StatShrDlgWznmVerImpexpIfi;
				if (dpcheng.StatShrDlgWznmVerImpexpImp) this.statshrimp = dpcheng.StatShrDlgWznmVerImpexpImp;
				if (dpcheng.StatShrDlgWznmVerImpexpLfi) this.statshrlfi = dpcheng.StatShrDlgWznmVerImpexpLfi;
				if (dpcheng.StatShrDlgWznmVerImpexpPpr) this.statshrppr = dpcheng.StatShrDlgWznmVerImpexpPpr;
				if (dpcheng.TagDlgWznmVerImpexp) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerImpexp);
					this.tag = dpcheng.TagDlgWznmVerImpexp;
				}
				if (dpcheng.TagDlgWznmVerImpexpIfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerImpexpIfi);
					this.tagifi = dpcheng.TagDlgWznmVerImpexpIfi;
				}
				if (dpcheng.TagDlgWznmVerImpexpImp) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerImpexpImp);
					this.tagimp = dpcheng.TagDlgWznmVerImpexpImp;
				}
				if (dpcheng.TagDlgWznmVerImpexpLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerImpexpLfi);
					this.taglfi = dpcheng.TagDlgWznmVerImpexpLfi;
				}
				if (dpcheng.TagDlgWznmVerImpexpPpr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerImpexpPpr);
					this.tagppr = dpcheng.TagDlgWznmVerImpexpPpr;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerImpexpData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerImpexpData") this.mergeDpchEngData(obj.dpcheng);
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

			continfimp: null,

			continflfi: null,

			continfppr: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrifi: null,

			statshrimp: null,

			statshrlfi: null,

			statshrppr: null,

			tag: null,

			tagifi: null,

			tagimp: null,

			taglfi: null,

			tagppr: null,

			contappifi: {
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
