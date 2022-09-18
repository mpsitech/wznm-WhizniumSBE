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
								v-model="continfgjt.TxtPrg"
								:label="taggjt.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('gjt', 'ButRunClick')"
										:disabled="!statshrgjt.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{taggjt.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('gjt', 'ButStoClick')"
										:disabled="!statshrgjt.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{taggjt.ButSto}}
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
		name: 'DlgWznmVerGenjtr',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVerGenjtr.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVerGenjtrDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVerGenjtr"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacgjt") != -1) dpchapp["ContIacDlgWznmVerGenjtrGjt"] = this.contiacgjt;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmVerGenjtrLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVerGenjtrData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVerGenjtrData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVerGenjtr) this.contiac = dpcheng.ContIacDlgWznmVerGenjtr;
				if (dpcheng.ContInfDlgWznmVerGenjtr) this.continf = dpcheng.ContInfDlgWznmVerGenjtr;
				if (dpcheng.ContInfDlgWznmVerGenjtrGjt) this.continfgjt = dpcheng.ContInfDlgWznmVerGenjtrGjt;
				if (dpcheng.ContInfDlgWznmVerGenjtrLfi) this.continflfi = dpcheng.ContInfDlgWznmVerGenjtrLfi;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVerGenjtr) this.statapp = dpcheng.StatAppDlgWznmVerGenjtr;
				if (dpcheng.StatShrDlgWznmVerGenjtr) this.statshr = dpcheng.StatShrDlgWznmVerGenjtr;
				if (dpcheng.StatShrDlgWznmVerGenjtrGjt) this.statshrgjt = dpcheng.StatShrDlgWznmVerGenjtrGjt;
				if (dpcheng.StatShrDlgWznmVerGenjtrLfi) this.statshrlfi = dpcheng.StatShrDlgWznmVerGenjtrLfi;
				if (dpcheng.TagDlgWznmVerGenjtr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerGenjtr);
					this.tag = dpcheng.TagDlgWznmVerGenjtr;
				}
				if (dpcheng.TagDlgWznmVerGenjtrGjt) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerGenjtrGjt);
					this.taggjt = dpcheng.TagDlgWznmVerGenjtrGjt;
				}
				if (dpcheng.TagDlgWznmVerGenjtrLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVerGenjtrLfi);
					this.taglfi = dpcheng.TagDlgWznmVerGenjtrLfi;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVerGenjtrData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVerGenjtrData") this.mergeDpchEngData(obj.dpcheng);
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

			continfgjt: null,

			continflfi: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrgjt: null,

			statshrlfi: null,

			tag: null,

			taggjt: null,

			taglfi: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
