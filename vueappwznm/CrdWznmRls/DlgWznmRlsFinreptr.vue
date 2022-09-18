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
								v-model="continffin.TxtPrg"
								:label="tagfin.CptPrg"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('fin', 'ButRunClick')"
										:disabled="!statshrfin.ButRunActive"
										class="my-1"
										color="primary"
									>
										{{tagfin.ButRun}}
									</v-btn>
									&#160;
									<v-btn
										v-on:click="handleButClick('fin', 'ButStoClick')"
										:disabled="!statshrfin.ButStoActive"
										class="my-1"
										color="primary"
									>
										{{tagfin.ButSto}}
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
								v-if="statshrres.DldAvail"
								download
								:href="hrefDld"
								target="_blank"
								:disabled="!statshrres.DldActive"
								class="my-1"
								color="primary"
							>
								{{tagres.Dld}}
							</v-btn>
							<v-text-field
								v-if="statshrres.TxtPrgAvail"
								class="my-1"
								readonly
								outlined
								v-model="continfres.TxtPrg"
								:label="tagres.CptPrg"
							/>

							<v-divider v-if="statshrres.Sep1Avail"/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('res', 'ButPsgClick')"
										:disabled="!statshrres.ButPsgActive"
										class="my-1"
										color="primary"
									>
										{{tagres.ButPsg}}
									</v-btn>
								</v-col>
							</v-row>

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
		name: 'DlgWznmRlsFinreptr',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmRlsFinreptr.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmRlsFinreptrDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmRlsFinreptr"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacfin") != -1) dpchapp["ContIacDlgWznmRlsFinreptrFin"] = this.contiacfin;
				if (mask.indexOf("contiacres") != -1) dpchapp["ContIacDlgWznmRlsFinreptrRes"] = this.contiacres;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmRlsFinreptrData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmRlsFinreptrData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmRlsFinreptr) this.contiac = dpcheng.ContIacDlgWznmRlsFinreptr;
				if (dpcheng.ContInfDlgWznmRlsFinreptr) this.continf = dpcheng.ContInfDlgWznmRlsFinreptr;
				if (dpcheng.ContInfDlgWznmRlsFinreptrFin) this.continffin = dpcheng.ContInfDlgWznmRlsFinreptrFin;
				if (dpcheng.ContInfDlgWznmRlsFinreptrRes) this.continfres = dpcheng.ContInfDlgWznmRlsFinreptrRes;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmRlsFinreptr) this.statapp = dpcheng.StatAppDlgWznmRlsFinreptr;
				if (dpcheng.StatShrDlgWznmRlsFinreptr) this.statshr = dpcheng.StatShrDlgWznmRlsFinreptr;
				if (dpcheng.StatShrDlgWznmRlsFinreptrFin) this.statshrfin = dpcheng.StatShrDlgWznmRlsFinreptrFin;
				if (dpcheng.StatShrDlgWznmRlsFinreptrRes) this.statshrres = dpcheng.StatShrDlgWznmRlsFinreptrRes;
				if (dpcheng.TagDlgWznmRlsFinreptr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsFinreptr);
					this.tag = dpcheng.TagDlgWznmRlsFinreptr;
				}
				if (dpcheng.TagDlgWznmRlsFinreptrFin) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsFinreptrFin);
					this.tagfin = dpcheng.TagDlgWznmRlsFinreptrFin;
				}
				if (dpcheng.TagDlgWznmRlsFinreptrRes) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmRlsFinreptrRes);
					this.tagres = dpcheng.TagDlgWznmRlsFinreptrRes;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmRlsFinreptrData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmRlsFinreptrData") this.mergeDpchEngData(obj.dpcheng);
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

			continffin: null,

			continfres: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrfin: null,

			statshrres: null,

			tag: null,

			tagfin: null,

			tagres: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
