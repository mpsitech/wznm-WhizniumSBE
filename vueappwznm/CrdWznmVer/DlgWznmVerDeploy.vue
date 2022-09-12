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
		name: 'DlgWznmVerDeploy',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerDeploy.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVerDeployDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmVerDeployDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerDeploy"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacifi") != -1) dpchapp["ContIacDlgWznmVerDeployIfi"] = this.contiacifi;
				if (mask.indexOf("contiacimp") != -1) dpchapp["ContIacDlgWznmVerDeployImp"] = this.contiacimp;
				if (mask.indexOf("contiacppr") != -1) dpchapp["ContIacDlgWznmVerDeployPpr"] = this.contiacppr;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmVerDeployLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerDeployData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerDeployData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVerDeploy) this.contiac = dpcheng.ContIacDlgWznmVerDeploy;
				if (dpcheng.ContInfDlgWznmVerDeploy) this.continf = dpcheng.ContInfDlgWznmVerDeploy;
				if (dpcheng.ContInfDlgWznmVerDeployImp) this.continfimp = dpcheng.ContInfDlgWznmVerDeployImp;
				if (dpcheng.ContInfDlgWznmVerDeployLfi) this.continflfi = dpcheng.ContInfDlgWznmVerDeployLfi;
				if (dpcheng.ContInfDlgWznmVerDeployPpr) this.continfppr = dpcheng.ContInfDlgWznmVerDeployPpr;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerDeploy) this.statapp = dpcheng.StatAppDlgWznmVerDeploy;
				if (dpcheng.StatShrDlgWznmVerDeploy) this.statshr = dpcheng.StatShrDlgWznmVerDeploy;
				if (dpcheng.StatShrDlgWznmVerDeployIfi) this.statshrifi = dpcheng.StatShrDlgWznmVerDeployIfi;
				if (dpcheng.StatShrDlgWznmVerDeployImp) this.statshrimp = dpcheng.StatShrDlgWznmVerDeployImp;
				if (dpcheng.StatShrDlgWznmVerDeployLfi) this.statshrlfi = dpcheng.StatShrDlgWznmVerDeployLfi;
				if (dpcheng.StatShrDlgWznmVerDeployPpr) this.statshrppr = dpcheng.StatShrDlgWznmVerDeployPpr;
				if (dpcheng.TagDlgWznmVerDeploy) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerDeploy);
					this.tag = dpcheng.TagDlgWznmVerDeploy;
				}
				if (dpcheng.TagDlgWznmVerDeployIfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerDeployIfi);
					this.tagifi = dpcheng.TagDlgWznmVerDeployIfi;
				}
				if (dpcheng.TagDlgWznmVerDeployImp) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerDeployImp);
					this.tagimp = dpcheng.TagDlgWznmVerDeployImp;
				}
				if (dpcheng.TagDlgWznmVerDeployLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerDeployLfi);
					this.taglfi = dpcheng.TagDlgWznmVerDeployLfi;
				}
				if (dpcheng.TagDlgWznmVerDeployPpr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerDeployPpr);
					this.tagppr = dpcheng.TagDlgWznmVerDeployPpr;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerDeployData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerDeployData") this.mergeDpchEngData(obj.dpcheng);
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
