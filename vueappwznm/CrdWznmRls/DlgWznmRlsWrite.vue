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
								v-model="contiacdet.ChkBso"
								v-on:change='updateEng(["contiacdet"])'
								:label="tagdet.CptBso"
							/>

						</v-card-text>
					</v-card>
				</v-tab-item>
				<v-tab-item>
					<v-card flat>
						<v-card-text>
							<v-file-input
								v-if="statshrcuc.UldAvail"
								outlined
								show-size
								:label="tagcuc.Cpt"
								v-model="contappcuc.file"
							>
							</v-file-input>
							<v-btn
								v-if="statshrcuc.UldAvail"
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
										v-on:click="handleButClick('wrc', 'ButAutClick')"
										:disabled="!statshrwrc.ButAutActive"
										class="my-1"
										color="primary"
									>
										{{tagwrc.ButAut}}
									</v-btn>
								</v-col>
							</v-row>

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
								v-if="statshrfia.DldAvail"
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
		name: 'DlgWznmRlsWrite',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmRlsWrite.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmRlsWriteDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmRlsWrite"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWznmRlsWriteDet"] = this.contiacdet;
				if (mask.indexOf("contiaccuc") != -1) dpchapp["ContIacDlgWznmRlsWriteCuc"] = this.contiaccuc;
				if (mask.indexOf("contiacwrc") != -1) dpchapp["ContIacDlgWznmRlsWriteWrc"] = this.contiacwrc;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmRlsWriteLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacfia") != -1) dpchapp["ContIacDlgWznmRlsWriteFia"] = this.contiacfia;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmRlsWriteData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmRlsWriteData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmRlsWrite) this.contiac = dpcheng.ContIacDlgWznmRlsWrite;
				if (dpcheng.ContIacDlgWznmRlsWriteDet) this.contiacdet = dpcheng.ContIacDlgWznmRlsWriteDet;
				if (dpcheng.ContInfDlgWznmRlsWrite) this.continf = dpcheng.ContInfDlgWznmRlsWrite;
				if (dpcheng.ContInfDlgWznmRlsWriteFia) this.continffia = dpcheng.ContInfDlgWznmRlsWriteFia;
				if (dpcheng.ContInfDlgWznmRlsWriteLfi) this.continflfi = dpcheng.ContInfDlgWznmRlsWriteLfi;
				if (dpcheng.ContInfDlgWznmRlsWriteWrc) this.continfwrc = dpcheng.ContInfDlgWznmRlsWriteWrc;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmRlsWrite) this.statapp = dpcheng.StatAppDlgWznmRlsWrite;
				if (dpcheng.StatShrDlgWznmRlsWrite) this.statshr = dpcheng.StatShrDlgWznmRlsWrite;
				if (dpcheng.StatShrDlgWznmRlsWriteCuc) this.statshrcuc = dpcheng.StatShrDlgWznmRlsWriteCuc;
				if (dpcheng.StatShrDlgWznmRlsWriteFia) this.statshrfia = dpcheng.StatShrDlgWznmRlsWriteFia;
				if (dpcheng.StatShrDlgWznmRlsWriteLfi) this.statshrlfi = dpcheng.StatShrDlgWznmRlsWriteLfi;
				if (dpcheng.StatShrDlgWznmRlsWriteWrc) this.statshrwrc = dpcheng.StatShrDlgWznmRlsWriteWrc;
				if (dpcheng.TagDlgWznmRlsWrite) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsWrite);
					this.tag = dpcheng.TagDlgWznmRlsWrite;
				}
				if (dpcheng.TagDlgWznmRlsWriteCuc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsWriteCuc);
					this.tagcuc = dpcheng.TagDlgWznmRlsWriteCuc;
				}
				if (dpcheng.TagDlgWznmRlsWriteDet) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsWriteDet);
					this.tagdet = dpcheng.TagDlgWznmRlsWriteDet;
				}
				if (dpcheng.TagDlgWznmRlsWriteFia) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsWriteFia);
					this.tagfia = dpcheng.TagDlgWznmRlsWriteFia;
				}
				if (dpcheng.TagDlgWznmRlsWriteLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsWriteLfi);
					this.taglfi = dpcheng.TagDlgWznmRlsWriteLfi;
				}
				if (dpcheng.TagDlgWznmRlsWriteWrc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsWriteWrc);
					this.tagwrc = dpcheng.TagDlgWznmRlsWriteWrc;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmRlsWriteData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmRlsWriteData") this.mergeDpchEngData(obj.dpcheng);
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
