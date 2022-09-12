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
							<v-checkbox
								class="my-1"
								v-model="contiacdet.ChkUsf"
								v-on:change='updateEng(["contiacdet"])'
								:label="tagdet.CptUsf"
							/>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								outlined
								show-size
								:label="tagcuc.Cpt"
								v-model="contappcuc.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('cuc')"
								:disabled="contappcuc.file == null"
								color="primary"
							>
								{{tagcuc.Uld}}
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
								v-model="continfwrc.TxtPrg"
								:label="tagwrc.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('wrc', 'ButRunClick')"
										:disabled="!statshrwrc.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagwrc.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('wrc', 'ButStoClick')"
										:disabled="!statshrwrc.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagwrc.ButSto}}
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
		name: 'DlgWznmAppWrite',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmAppWrite.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmAppWriteDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmAppWriteDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmAppWrite"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWznmAppWriteDet"] = this.contiacdet;
				if (mask.indexOf("contiaccuc") != -1) dpchapp["ContIacDlgWznmAppWriteCuc"] = this.contiaccuc;
				if (mask.indexOf("contiacwrc") != -1) dpchapp["ContIacDlgWznmAppWriteWrc"] = this.contiacwrc;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmAppWriteLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacfia") != -1) dpchapp["ContIacDlgWznmAppWriteFia"] = this.contiacfia;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmAppWriteData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmAppWriteData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmAppWrite) this.contiac = dpcheng.ContIacDlgWznmAppWrite;
				if (dpcheng.ContIacDlgWznmAppWriteDet) this.contiacdet = dpcheng.ContIacDlgWznmAppWriteDet;
				if (dpcheng.ContInfDlgWznmAppWrite) this.continf = dpcheng.ContInfDlgWznmAppWrite;
				if (dpcheng.ContInfDlgWznmAppWriteFia) this.continffia = dpcheng.ContInfDlgWznmAppWriteFia;
				if (dpcheng.ContInfDlgWznmAppWriteLfi) this.continflfi = dpcheng.ContInfDlgWznmAppWriteLfi;
				if (dpcheng.ContInfDlgWznmAppWriteWrc) this.continfwrc = dpcheng.ContInfDlgWznmAppWriteWrc;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmAppWrite) this.statapp = dpcheng.StatAppDlgWznmAppWrite;
				if (dpcheng.StatShrDlgWznmAppWrite) this.statshr = dpcheng.StatShrDlgWznmAppWrite;
				if (dpcheng.StatShrDlgWznmAppWriteCuc) this.statshrcuc = dpcheng.StatShrDlgWznmAppWriteCuc;
				if (dpcheng.StatShrDlgWznmAppWriteFia) this.statshrfia = dpcheng.StatShrDlgWznmAppWriteFia;
				if (dpcheng.StatShrDlgWznmAppWriteLfi) this.statshrlfi = dpcheng.StatShrDlgWznmAppWriteLfi;
				if (dpcheng.StatShrDlgWznmAppWriteWrc) this.statshrwrc = dpcheng.StatShrDlgWznmAppWriteWrc;
				if (dpcheng.TagDlgWznmAppWrite) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppWrite);
					this.tag = dpcheng.TagDlgWznmAppWrite;
				}
				if (dpcheng.TagDlgWznmAppWriteCuc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppWriteCuc);
					this.tagcuc = dpcheng.TagDlgWznmAppWriteCuc;
				}
				if (dpcheng.TagDlgWznmAppWriteDet) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppWriteDet);
					this.tagdet = dpcheng.TagDlgWznmAppWriteDet;
				}
				if (dpcheng.TagDlgWznmAppWriteFia) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppWriteFia);
					this.tagfia = dpcheng.TagDlgWznmAppWriteFia;
				}
				if (dpcheng.TagDlgWznmAppWriteLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppWriteLfi);
					this.taglfi = dpcheng.TagDlgWznmAppWriteLfi;
				}
				if (dpcheng.TagDlgWznmAppWriteWrc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmAppWriteWrc);
					this.tagwrc = dpcheng.TagDlgWznmAppWriteWrc;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmAppWriteData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmAppWriteData") this.mergeDpchEngData(obj.dpcheng);
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

			continffia: null,

			continflfi: null,

			continfwrc: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrcuc: null,

			statshrfia: null,

			statshrlfi: null,

			statshrwrc: null,

			tag: null,

			tagcuc: null,

			tagdet: null,

			tagfia: null,

			taglfi: null,

			tagwrc: null,

			contappcuc: {
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
