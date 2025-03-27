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
								v-model="continfwri.TxtPrg"
								:label="tagwri.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('wri', 'ButRunClick')"
										:disabled="!statshrwri.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagwri.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('wri', 'ButStoClick')"
										:disabled="!statshrwri.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagwri.ButSto}}
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
								:disabled="!statshrmfi.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagmfi.Dld}}
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
		name: 'DlgWznmVisExpstr',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVisExpstr.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVisExpstrDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVisExpstr"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacwri") != -1) dpchapp["ContIacDlgWznmVisExpstrWri"] = this.contiacwri;
				if (mask.indexOf("contiacmfi") != -1) dpchapp["ContIacDlgWznmVisExpstrMfi"] = this.contiacmfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVisExpstrData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVisExpstrData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVisExpstr) this.contiac = dpcheng.ContIacDlgWznmVisExpstr;
				if (dpcheng.ContInfDlgWznmVisExpstr) this.continf = dpcheng.ContInfDlgWznmVisExpstr;
				if (dpcheng.ContInfDlgWznmVisExpstrMfi) this.continfmfi = dpcheng.ContInfDlgWznmVisExpstrMfi;
				if (dpcheng.ContInfDlgWznmVisExpstrWri) this.continfwri = dpcheng.ContInfDlgWznmVisExpstrWri;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVisExpstr) this.statapp = dpcheng.StatAppDlgWznmVisExpstr;
				if (dpcheng.StatShrDlgWznmVisExpstr) this.statshr = dpcheng.StatShrDlgWznmVisExpstr;
				if (dpcheng.StatShrDlgWznmVisExpstrMfi) this.statshrmfi = dpcheng.StatShrDlgWznmVisExpstrMfi;
				if (dpcheng.StatShrDlgWznmVisExpstrWri) this.statshrwri = dpcheng.StatShrDlgWznmVisExpstrWri;
				if (dpcheng.TagDlgWznmVisExpstr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisExpstr);
					this.tag = dpcheng.TagDlgWznmVisExpstr;
				}
				if (dpcheng.TagDlgWznmVisExpstrMfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisExpstrMfi);
					this.tagmfi = dpcheng.TagDlgWznmVisExpstrMfi;
				}
				if (dpcheng.TagDlgWznmVisExpstrWri) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisExpstrWri);
					this.tagwri = dpcheng.TagDlgWznmVisExpstrWri;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVisExpstrData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVisExpstrData") this.mergeDpchEngData(obj.dpcheng);
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

			continfmfi: null,

			continfwri: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrmfi: null,

			statshrwri: null,

			tag: null,

			tagmfi: null,

			tagwri: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
