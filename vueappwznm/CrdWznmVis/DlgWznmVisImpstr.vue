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
		name: 'DlgWznmVisImpstr',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmVisImpstr.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmVisImpstrDo": {
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

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmVisImpstr"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacifi") != -1) dpchapp["ContIacDlgWznmVisImpstrIfi"] = this.contiacifi;
				if (mask.indexOf("contiacimp") != -1) dpchapp["ContIacDlgWznmVisImpstrImp"] = this.contiacimp;
				if (mask.indexOf("contiaclfi") != -1) dpchapp["ContIacDlgWznmVisImpstrLfi"] = this.contiaclfi;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmVisImpstrData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmVisImpstrData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmVisImpstr) this.contiac = dpcheng.ContIacDlgWznmVisImpstr;
				if (dpcheng.ContInfDlgWznmVisImpstr) this.continf = dpcheng.ContInfDlgWznmVisImpstr;
				if (dpcheng.ContInfDlgWznmVisImpstrImp) this.continfimp = dpcheng.ContInfDlgWznmVisImpstrImp;
				if (dpcheng.ContInfDlgWznmVisImpstrLfi) this.continflfi = dpcheng.ContInfDlgWznmVisImpstrLfi;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmVisImpstr) this.statapp = dpcheng.StatAppDlgWznmVisImpstr;
				if (dpcheng.StatShrDlgWznmVisImpstr) this.statshr = dpcheng.StatShrDlgWznmVisImpstr;
				if (dpcheng.StatShrDlgWznmVisImpstrIfi) this.statshrifi = dpcheng.StatShrDlgWznmVisImpstrIfi;
				if (dpcheng.StatShrDlgWznmVisImpstrImp) this.statshrimp = dpcheng.StatShrDlgWznmVisImpstrImp;
				if (dpcheng.StatShrDlgWznmVisImpstrLfi) this.statshrlfi = dpcheng.StatShrDlgWznmVisImpstrLfi;
				if (dpcheng.TagDlgWznmVisImpstr) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisImpstr);
					this.tag = dpcheng.TagDlgWznmVisImpstr;
				}
				if (dpcheng.TagDlgWznmVisImpstrIfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisImpstrIfi);
					this.tagifi = dpcheng.TagDlgWznmVisImpstrIfi;
				}
				if (dpcheng.TagDlgWznmVisImpstrImp) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisImpstrImp);
					this.tagimp = dpcheng.TagDlgWznmVisImpstrImp;
				}
				if (dpcheng.TagDlgWznmVisImpstrLfi) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmVisImpstrLfi);
					this.taglfi = dpcheng.TagDlgWznmVisImpstrLfi;
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmVisImpstrData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmVisImpstrData") this.mergeDpchEngData(obj.dpcheng);
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

			statshrifi: null,

			statshrimp: null,

			statshrlfi: null,

			tag: null,

			tagifi: null,

			tagimp: null,

			taglfi: null,

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
