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
		name: 'DlgWznmVisWrite',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVisWrite.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVisWriteDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVisWrite"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacwrc") != -1) dpchapp["ContIacDlgWznmVisWriteWrc"] = this.contiacwrc;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmVisWriteLfi"] = this.contiaclfi;
				if (mask.indexOf("contiacfia") != -1) dpchapp["ContIacDlgWznmVisWriteFia"] = this.contiacfia;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVisWriteData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVisWriteData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVisWrite) this.contiac = dpcheng.ContIacDlgWznmVisWrite;
				if (dpcheng.ContInfDlgWznmVisWrite) this.continf = dpcheng.ContInfDlgWznmVisWrite;
				if (dpcheng.ContInfDlgWznmVisWriteFia) this.continffia = dpcheng.ContInfDlgWznmVisWriteFia;
				if (dpcheng.ContInfDlgWznmVisWriteLfi) this.continflfi = dpcheng.ContInfDlgWznmVisWriteLfi;
				if (dpcheng.ContInfDlgWznmVisWriteWrc) this.continfwrc = dpcheng.ContInfDlgWznmVisWriteWrc;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVisWrite) this.statapp = dpcheng.StatAppDlgWznmVisWrite;
				if (dpcheng.StatShrDlgWznmVisWrite) this.statshr = dpcheng.StatShrDlgWznmVisWrite;
				if (dpcheng.StatShrDlgWznmVisWriteFia) this.statshrfia = dpcheng.StatShrDlgWznmVisWriteFia;
				if (dpcheng.StatShrDlgWznmVisWriteLfi) this.statshrlfi = dpcheng.StatShrDlgWznmVisWriteLfi;
				if (dpcheng.StatShrDlgWznmVisWriteWrc) this.statshrwrc = dpcheng.StatShrDlgWznmVisWriteWrc;
				if (dpcheng.TagDlgWznmVisWrite) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisWrite);
					this.tag = dpcheng.TagDlgWznmVisWrite;
				}
				if (dpcheng.TagDlgWznmVisWriteFia) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisWriteFia);
					this.tagfia = dpcheng.TagDlgWznmVisWriteFia;
				}
				if (dpcheng.TagDlgWznmVisWriteLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisWriteLfi);
					this.taglfi = dpcheng.TagDlgWznmVisWriteLfi;
				}
				if (dpcheng.TagDlgWznmVisWriteWrc) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisWriteWrc);
					this.tagwrc = dpcheng.TagDlgWznmVisWriteWrc;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVisWriteData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVisWriteData") this.mergeDpchEngData(obj.dpcheng);
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

			continflfi: null,

			continfwrc: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrfia: null,

			statshrlfi: null,

			statshrwrc: null,

			tag: null,

			tagfia: null,

			taglfi: null,

			tagwrc: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
