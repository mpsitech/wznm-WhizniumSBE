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
								v-model="contiacdet.TxfFnm"
								:label="tagdet.CptFnm"
							/>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupRet"
								:items="feedFDetPupRet"
								:label='tagdet.CptRet'
								v-on:change="handlePupChange('det', 'numFPupRet', contappdet.fiFPupRet)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfReu"
								:label="tagdet.CptReu"
							/>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupCnt"
								:items="feedFDetPupCnt"
								:label='tagdet.CptCnt'
								v-on:change="handlePupChange('det', 'numFPupCnt', contappdet.fiFPupCnt)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

							<v-select
								class="my-1"
								v-model="contappdet.fiFPupMim"
								:items="feedFDetPupMim"
								:label='tagdet.CptMim'
								v-on:change="handlePupChange('det', 'numFPupMim', contappdet.fiFPupMim)"
							>
								<template v-slot:selection="{item}">{{item.tit1}}</template>
								<template v-slot:item="{item}">{{item.tit1}}</template>
							</v-select>

							<v-text-field
								class="my-1"
								v-model="contiacdet.TxfCmt"
								:label="tagdet.CptCmt"
							/>

							<v-divider/>

							<v-row class="my-1">
								<v-col>
									<v-btn
										v-on:click="handleButClick('det', 'ButCreClick')"
										:disabled="!statshrdet.ButCreActive"
										class="my-1"
										color="primary"
									>
										{{tagdet.ButCre}}
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
								:label="tagfil.Cpt"
								v-model="contappfil.file"
							>
							</v-file-input>
							<v-btn
								v-on:click="handleButUploadClick('fil')"
								:disabled="contappfil.file == null"
								color="primary"
							>
								{{tagfil.Uld}}
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
		name: 'DlgWznmFilNew',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("DlgWznmFilNew.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppDlgWznmFilNewDo": {
						"scrJref": this.scrJref
					}
				};

				if (ditshort != "") ditshort = ditshort.charAt(0).toUpperCase() + ditshort.slice(1);
				dpchapp["DpchAppDlgWznmFilNewDo"]["srefIxVDo" + ditshort] = ctlsref;

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButUploadClick: function(ditshort) {
				this.$emit("upload", {scrJref: this.scrJref, file: this["contapp" + ditshort].file});
			},

			handlePupChange: function(ditshort, cisref, fi) {
				this["contiac" + ditshort][cisref] = fi.num;

				this.updateEng(["contiac" + ditshort]);
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacDlgWznmFilNew"] = this.contiac;
				/*
				*/
				if (mask.indexOf("contiacdet") != -1) dpchapp["ContIacDlgWznmFilNewDet"] = this.contiacdet;
				if (mask.indexOf("contiacfil") != -1) dpchapp["ContIacDlgWznmFilNewFil"] = this.contiacfil;
				/*
				*/

				//console.log(JSON.stringify({"DpchAppDlgWznmFilNewData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppDlgWznmFilNewData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				if (dpcheng.ContIacDlgWznmFilNew) this.contiac = dpcheng.ContIacDlgWznmFilNew;
				if (dpcheng.ContIacDlgWznmFilNewDet) this.contiacdet = dpcheng.ContIacDlgWznmFilNewDet;
				if (dpcheng.ContInfDlgWznmFilNew) this.continf = dpcheng.ContInfDlgWznmFilNew;
				if (dpcheng.FeedFDetPupCnt) this.feedFDetPupCnt = dpcheng.FeedFDetPupCnt;
				if (dpcheng.FeedFDetPupMim) this.feedFDetPupMim = dpcheng.FeedFDetPupMim;
				if (dpcheng.FeedFDetPupRet) this.feedFDetPupRet = dpcheng.FeedFDetPupRet;
				if (dpcheng.FeedFDse) this.feedFDse = dpcheng.FeedFDse;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppDlgWznmFilNew) this.statapp = dpcheng.StatAppDlgWznmFilNew;
				if (dpcheng.StatShrDlgWznmFilNew) this.statshr = dpcheng.StatShrDlgWznmFilNew;
				if (dpcheng.StatShrDlgWznmFilNewDet) this.statshrdet = dpcheng.StatShrDlgWznmFilNewDet;
				if (dpcheng.StatShrDlgWznmFilNewFil) this.statshrfil = dpcheng.StatShrDlgWznmFilNewFil;
				if (dpcheng.TagDlgWznmFilNew) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmFilNew);
					this.tag = dpcheng.TagDlgWznmFilNew;
				}
				if (dpcheng.TagDlgWznmFilNewDet) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmFilNewDet);
					this.tagdet = dpcheng.TagDlgWznmFilNewDet;
				}
				if (dpcheng.TagDlgWznmFilNewFil) {
					Wznm.unescapeBlock(dpcheng.TagDlgWznmFilNewFil);
					this.tagfil = dpcheng.TagDlgWznmFilNewFil;
				}
				if (dpcheng.ContIacDlgWznmFilNewDet) {
					for (let i = 0; i < this.feedFDetPupRet.length; i++)
						if (this.feedFDetPupRet[i].num == this.contiacdet.numFPupRet) {
							this.contappdet.fiFPupRet = this.feedFDetPupRet[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupCnt.length; i++)
						if (this.feedFDetPupCnt[i].num == this.contiacdet.numFPupCnt) {
							this.contappdet.fiFPupCnt = this.feedFDetPupCnt[i];
							break;
						}
					for (let i = 0; i < this.feedFDetPupMim.length; i++)
						if (this.feedFDetPupMim[i].num == this.contiacdet.numFPupMim) {
							this.contappdet.fiFPupMim = this.feedFDetPupMim[i];
							break;
						}
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
				if (srefIxWznmVDpch == "DpchEngDlgWznmFilNewData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngDlgWznmFilNewData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {

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

			feedFDetPupCnt: null,

			feedFDetPupMim: null,

			feedFDetPupRet: null,

			feedFDse: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			statshrdet: null,

			statshrfil: null,

			tag: null,

			tagdet: null,

			tagfil: null,

			contappdet: {
				fiFPupRet: null,

				fiFPupCnt: null,

				fiFPupMim: null,

			},

			contappfil: {
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
