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
								v-if="statshrdet.TxfGrlAvail"
								class="my-1"
								v-model="contiacdet.TxfGrl"
								:label="tagdet.CptGrl"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('det', 'ButStaClick')"
										:disabled="!statshrdet.ButStaActive"
										class="my-1"
										color="primary"
									>
										{{tagdet.ButSta}}
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
								v-if="statshrini.UldAvail"
								outlined
								show-size
								:label="tagini.Cpt"
								v-model="contappini.file"
							>
							</v-file-input>
							<v-btn
								v-if="statshrini.UldAvail"
								v-on:click="handleButUploadClick('ini')"
								:disabled="contappini.file == null"
								color="primary"
							>
								{{tagini.Uld}}
							</v-btn>
							<v-text-field
								v-if="statshrini.TxtPrgAvail"
								class="my-1"
								readonly
								outlined
								v-model="continfini.TxtPrg"
								:label="tagini.CptPrg"
							/>

							<v-divider v-if="statshrini.Sep1Avail"/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('ini', 'ButClgClick')"
										:disabled="!statshrini.ButClgActive"
										class="my-1"
										color="primary"
									>
										{{tagini.ButClg}}
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
		name: 'DlgWznmRlsStareptr',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmRlsStareptr.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmRlsStareptrDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmRlsStareptr"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWznmRlsStareptrDet"] = this.contiacdet;
				if (mask.indexOf("contiacini") != -1) dpchapp["ContIacDlgWznmRlsStareptrIni"] = this.contiacini;
				if (mask.indexOf("contiacext") != -1) dpchapp["ContIacDlgWznmRlsStareptrExt"] = this.contiacext;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmRlsStareptrLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmRlsStareptrData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmRlsStareptrData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmRlsStareptr) this.contiac = dpcheng.ContIacDlgWznmRlsStareptr;
				if (dpcheng.ContIacDlgWznmRlsStareptrDet) this.contiacdet = dpcheng.ContIacDlgWznmRlsStareptrDet;
				if (dpcheng.ContInfDlgWznmRlsStareptr) this.continf = dpcheng.ContInfDlgWznmRlsStareptr;
				if (dpcheng.ContInfDlgWznmRlsStareptrExt) this.continfext = dpcheng.ContInfDlgWznmRlsStareptrExt;
				if (dpcheng.ContInfDlgWznmRlsStareptrIni) this.continfini = dpcheng.ContInfDlgWznmRlsStareptrIni;
				if (dpcheng.ContInfDlgWznmRlsStareptrLfi) this.continflfi = dpcheng.ContInfDlgWznmRlsStareptrLfi;
				if (dpcheng.FeedFDetRbuBrt) this.feedFDetRbuBrt = dpcheng.FeedFDetRbuBrt;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmRlsStareptr) this.statapp = dpcheng.StatAppDlgWznmRlsStareptr;
				if (dpcheng.StatShrDlgWznmRlsStareptr) this.statshr = dpcheng.StatShrDlgWznmRlsStareptr;
				if (dpcheng.StatShrDlgWznmRlsStareptrDet) this.statshrdet = dpcheng.StatShrDlgWznmRlsStareptrDet;
				if (dpcheng.StatShrDlgWznmRlsStareptrExt) this.statshrext = dpcheng.StatShrDlgWznmRlsStareptrExt;
				if (dpcheng.StatShrDlgWznmRlsStareptrIni) this.statshrini = dpcheng.StatShrDlgWznmRlsStareptrIni;
				if (dpcheng.StatShrDlgWznmRlsStareptrLfi) this.statshrlfi = dpcheng.StatShrDlgWznmRlsStareptrLfi;
				if (dpcheng.TagDlgWznmRlsStareptr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsStareptr);
					this.tag = dpcheng.TagDlgWznmRlsStareptr;
				}
				if (dpcheng.TagDlgWznmRlsStareptrDet) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsStareptrDet);
					this.tagdet = dpcheng.TagDlgWznmRlsStareptrDet;
				}
				if (dpcheng.TagDlgWznmRlsStareptrExt) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsStareptrExt);
					this.tagext = dpcheng.TagDlgWznmRlsStareptrExt;
				}
				if (dpcheng.TagDlgWznmRlsStareptrIni) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsStareptrIni);
					this.tagini = dpcheng.TagDlgWznmRlsStareptrIni;
				}
				if (dpcheng.TagDlgWznmRlsStareptrLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsStareptrLfi);
					this.taglfi = dpcheng.TagDlgWznmRlsStareptrLfi;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmRlsStareptrData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmRlsStareptrData") this.mergeDpchEngData(obj.dpcheng);
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

			contiacdet: null,

			continf: null,

			continfext: null,

			continfini: null,

			continflfi: null,

			feedFDetRbuBrt: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrdet: null,

			statshrext: null,

			statshrini: null,

			statshrlfi: null,

			tag: null,

			tagdet: null,

			tagext: null,

			tagini: null,

			taglfi: null,

			contappini: {
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
