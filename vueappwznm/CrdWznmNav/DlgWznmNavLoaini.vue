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
							<v-file-input
								outlined
								show-size
								:label="tagacv.Cpt"
								v-model="contappacv.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('acv')"
								:disabled="contappacv.file == null"
								color="primary"
							>
								{{tagacv.Uld}}
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
		name: 'DlgWznmNavLoaini',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmNavLoaini.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmNavLoainiDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmNavLoainiDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmNavLoaini"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacifi") != -1) dpchapp["ContIacDlgWznmNavLoainiIfi"] = this.contiacifi;
				if (mask.indexOf("contiacimp") != -1) dpchapp["ContIacDlgWznmNavLoainiImp"] = this.contiacimp;
				if (mask.indexOf("contiacacv") != -1) dpchapp["ContIacDlgWznmNavLoainiAcv"] = this.contiacacv;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmNavLoainiLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmNavLoainiData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmNavLoainiData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmNavLoaini) this.contiac = dpcheng.ContIacDlgWznmNavLoaini;
				if (dpcheng.ContInfDlgWznmNavLoaini) this.continf = dpcheng.ContInfDlgWznmNavLoaini;
				if (dpcheng.ContInfDlgWznmNavLoainiImp) this.continfimp = dpcheng.ContInfDlgWznmNavLoainiImp;
				if (dpcheng.ContInfDlgWznmNavLoainiLfi) this.continflfi = dpcheng.ContInfDlgWznmNavLoainiLfi;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmNavLoaini) this.statapp = dpcheng.StatAppDlgWznmNavLoaini;
				if (dpcheng.StatShrDlgWznmNavLoaini) this.statshr = dpcheng.StatShrDlgWznmNavLoaini;
				if (dpcheng.StatShrDlgWznmNavLoainiAcv) this.statshracv = dpcheng.StatShrDlgWznmNavLoainiAcv;
				if (dpcheng.StatShrDlgWznmNavLoainiIfi) this.statshrifi = dpcheng.StatShrDlgWznmNavLoainiIfi;
				if (dpcheng.StatShrDlgWznmNavLoainiImp) this.statshrimp = dpcheng.StatShrDlgWznmNavLoainiImp;
				if (dpcheng.StatShrDlgWznmNavLoainiLfi) this.statshrlfi = dpcheng.StatShrDlgWznmNavLoainiLfi;
				if (dpcheng.TagDlgWznmNavLoaini) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmNavLoaini);
					this.tag = dpcheng.TagDlgWznmNavLoaini;
				}
				if (dpcheng.TagDlgWznmNavLoainiAcv) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmNavLoainiAcv);
					this.tagacv = dpcheng.TagDlgWznmNavLoainiAcv;
				}
				if (dpcheng.TagDlgWznmNavLoainiIfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmNavLoainiIfi);
					this.tagifi = dpcheng.TagDlgWznmNavLoainiIfi;
				}
				if (dpcheng.TagDlgWznmNavLoainiImp) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmNavLoainiImp);
					this.tagimp = dpcheng.TagDlgWznmNavLoainiImp;
				}
				if (dpcheng.TagDlgWznmNavLoainiLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmNavLoainiLfi);
					this.taglfi = dpcheng.TagDlgWznmNavLoainiLfi;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmNavLoainiData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmNavLoainiData") this.mergeDpchEngData(obj.dpcheng);
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

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshracv: null,

			statshrifi: null,

			statshrimp: null,

			statshrlfi: null,

			tag: null,

			tagacv: null,

			tagifi: null,

			tagimp: null,

			taglfi: null,

			contappacv: {
				file: null,

			},

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
