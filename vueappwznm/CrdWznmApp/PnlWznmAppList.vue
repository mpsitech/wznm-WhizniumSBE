<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>
						<span>{{Cpt}}</span>
					</div>
				</v-col>
				<v-col cols="4" align="end">
					&#160;
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClipboardClick()"
						:value="1"
					>
						<v-icon color="white">mdi-clipboard</v-icon>
					</v-btn>
					&#160;&#160;
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButNewClick')"
						:value="1"
					>
						<v-icon color="white">mdi-file-plus</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButDeleteClick')"
						:value="1"
						:disabled="!statshr.ButDeleteActive"
					>
						<v-icon color="white">mdi-file-remove</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButFilterClick')"
						:value="1"
					>
						<v-icon color="white">{{contapp.ButFilterOn ? 'mdi-filter' : 'mdi-filter-off'}}</v-icon>
					</v-btn>
					&#160;&#160;
					&#160;
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='regd'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButMinimizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-minus-circle</v-icon>
					</v-btn>
					&#160;
					<v-btn
						v-if="statshr.srefIxWznmVExpstate=='mind'"
						fab
						small
						light
						color="primary"
						v-on:click="handleButClick('ButRegularizeClick')"
						:value="1"
					>
						<v-icon color="white">mdi-plus-circle</v-icon>
					</v-btn>
				</v-col>
			</v-row>
		</v-card-title>

		<v-card-text
			v-if="statshr.srefIxWznmVExpstate=='regd'"
		>
			<v-data-table
				:headers="headers"
				:items="contapp.rows"
				:items-per-page="10"
				item-key="jnum"
				single-select
				show-select
				class="elevation-1 my-3"
				v-on:item-selected="handleSelect"
			/>

			<v-row>
				<v-col align="end">
					<v-tooltip left>
						<template v-slot:activator="{on,attrs}">
							<v-btn
								fab
								small
								light
								v-bind="attrs"
								v-on="on"
								:color="fiFCsiQst.sref == 'ong' ? 'orange' : fiFCsiQst.sref == 'red' ? 'red' : fiFCsiQst.sref == 'yel' ? 'yellow' : fiFCsiQst.sref == 'grn' ? 'green' : 'primary'"
								v-on:click="handleButClick('ButRefreshClick')"
							>
								<v-icon color="white">mdi-refresh</v-icon>
							</v-btn>
						</template>
						{{fiFCsiQst.tit1}}
					</v-tooltip>
				</v-col>
			</v-row>
		</v-card-text>
	</v-card>
</template>

<script>
	import Wznm from '../../scripts/Wznm';

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'PnlWznmAppList',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmAppList.mounted() with scrJref = " + this.scrJref);

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

			handleButClick: function(ctlsref) {
				const dpchapp = {
					"DpchAppWznmAppListDo": {
						"scrJref": this.scrJref,
						"srefIxVDo": ctlsref
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			handleButClipboardClick: function() {
				/*
				*/
				Wznm.copyToClipboard(document, this.continf, this.rst, this.statshrqry, this.tag,
							["Grp","Own","Sho","Tit","","Trg","Ver"],
							["grp","own","sho","tit","trg","trg2","ver"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWznmAppListData": {
						"scrJref": this.scrJref,
						"StgIacQryWznmAppList": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmAppList"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmAppListData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmAppListData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmAppList) this.contiac = dpcheng.ContIacWznmAppList;
				if (dpcheng.ContInfWznmAppList) this.continf = dpcheng.ContInfWznmAppList;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.FeedFTos) this.feedFTos = dpcheng.FeedFTos;
				if (dpcheng.StatShrWznmAppList) this.statshr = dpcheng.StatShrWznmAppList;
				if (dpcheng.StgIacWznmAppList) this.stgiac = dpcheng.StgIacWznmAppList;
				if (dpcheng.TagWznmAppList) {
					Wznm.unescapeBlock(dpcheng.TagWznmAppList);
					this.tag = dpcheng.TagWznmAppList;
				}
				if (dpcheng.ListWznmQAppList) this.rst = dpcheng.ListWznmQAppList;
				if (dpcheng.StatAppQryWznmAppList) this.statappqry = dpcheng.StatAppQryWznmAppList;
				if (dpcheng.StatShrQryWznmAppList) this.statshrqry = dpcheng.StatShrQryWznmAppList;
				if (dpcheng.StgIacQryWznmAppList) this.stgiacqry = dpcheng.StgIacQryWznmAppList;
				if (dpcheng.ContInfWznmAppList) {
					if (!this.continf.ButFilterOn) this.contapp.ButFilterOn = 0;
					else this.contapp.ButFilterOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWznmAppList) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoGrp", text: this.tag.TcoGrp}, {value: "TcoOwn", text: this.tag.TcoOwn}, {value: "TcoSho", text: this.tag.TcoSho}, {value: "TcoTit", text: this.tag.TcoTit}, {value: "TcoTrg", text: this.tag.TcoTrg}, {value: "TcoVer", text: this.tag.TcoVer});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWznmQAppList) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoGrp: rec["grp"], TcoOwn: rec["own"], TcoSho: rec["sho"], TcoTit: rec["tit"], TcoTrg: rec["trg2"], TcoVer: rec["ver"]})
						/*
						*/

					}

					this.contapp.rows = rows;
				}
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
				if (srefIxWznmVDpch == "DpchEngWznmAppListData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmAppListData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			/*
			*/
			Cpt: function() {
				if (this.statshr.srefIxWznmVExpstate == "mind") return(this.tag.Cpt + " (" + this.statshrqry.ntot + ")");
				return this.tag.Cpt;
			},
			/*
			*/

			headers: function() {
				return this.contapp.tcos.filter(x => x.value != "jnum")
			},

			fiFCsiQst: function() {
				if (this.feedFCsiQst && this.continf)
					for (var i = 0; i < this.feedFCsiQst.length; i++)
						if (this.feedFCsiQst[i].num == this.continf.numFCsiQst) return this.feedFCsiQst[i];

				return {sref: "gry", tit1: "invalid"}
			}
		},

		data: () => ({
			initdone: false,

			/*
			*/
			contiac: null,

			continf: null,

			feedFCsiQst: null,

			feedFTos: null,

			statshr: null,

			stgiac: null,

			tag: null,

			rst: null,

			statappqry: null,

			statshrqry: null,

			stgiacqry: null,

			contapp: {
				ButFilterOn: 0,

				tcos: [],
				rows: [],

			},
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
