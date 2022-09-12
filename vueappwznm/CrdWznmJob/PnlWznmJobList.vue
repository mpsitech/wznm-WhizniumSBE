<template>
	<v-card v-if="initdone" class="pa-3 my-3 mx-auto" elevation="4">
		<v-card-title>
			<v-row>
				<v-col cols="8">
					<div>
						<span>{{tag.Cpt}}</span>
						<span class="caption">{{TxtFor}}</span>
						<span>{{continf.TxtPre}}</span>
						<span>{{Cpt2}}</span>
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
		name: 'PnlWznmJobList',

		props: {
			scrJref: String
		},

		mounted() {
			//console.log("PnlWznmJobList.mounted() with scrJref = " + this.scrJref);

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
					"DpchAppWznmJobListDo": {
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
							["Srf","","Typ","Ver","","Ret","Reu","Gbl","Cls","Shd"],
							["srf","typ","typ2","ver","ret","ret2","reu","gbl","cls","shd"]);
				/*
				*/
			},

			handleSelect: function(obj) {
				var stgiacqry = this.stgiacqry;

				if (!obj.value) stgiacqry.jnum = 0;
				else stgiacqry.jnum = obj.item.jnum;

				const dpchapp = {
					"DpchAppWznmJobListData": {
						"scrJref": this.scrJref,
						"StgIacQryWznmJobList": stgiacqry
					}
				};

				this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppDataDoReply"});
			},

			updateEng: function(mask) {
				var dpchapp = {
					"scrJref": this.scrJref
				}

				if (mask.indexOf("contiac") != -1) dpchapp["ContIacWznmJobList"] = this.contiac;

				//console.log(JSON.stringify({"DpchAppWznmJobListData": dpchapp}))

				this.$emit("request", {scrJref: this.scrJref, dpchapp: {"DpchAppWznmJobListData": dpchapp}, then: "handleDpchAppDataDoReply"});
			},

			mergeDpchEngData: function(dpcheng) {
				/*
				<!-- IP mergeDpchEngData - BEGIN -->
				*/
				if (dpcheng.ContIacWznmJobList) this.contiac = dpcheng.ContIacWznmJobList;
				if (dpcheng.ContInfWznmJobList) this.continf = dpcheng.ContInfWznmJobList;
				if (dpcheng.FeedFCsiQst) this.feedFCsiQst = dpcheng.FeedFCsiQst;
				if (dpcheng.FeedFTos) this.feedFTos = dpcheng.FeedFTos;
				if (dpcheng.StatShrWznmJobList) this.statshr = dpcheng.StatShrWznmJobList;
				if (dpcheng.StgIacWznmJobList) this.stgiac = dpcheng.StgIacWznmJobList;
				if (dpcheng.TagWznmJobList) {
					Wznm.unescapeBlock(dpcheng.TagWznmJobList);
					this.tag = dpcheng.TagWznmJobList;
				}
				if (dpcheng.ListWznmQJobList) this.rst = dpcheng.ListWznmQJobList;
				if (dpcheng.StatAppQryWznmJobList) this.statappqry = dpcheng.StatAppQryWznmJobList;
				if (dpcheng.StatShrQryWznmJobList) this.statshrqry = dpcheng.StatShrQryWznmJobList;
				if (dpcheng.StgIacQryWznmJobList) this.stgiacqry = dpcheng.StgIacQryWznmJobList;
				if (dpcheng.ContInfWznmJobList) {
					if (!this.continf.ButFilterOn) this.contapp.ButFilterOn = 0;
					else this.contapp.ButFilterOn = 1;
				}
				/*
				<!-- IP mergeDpchEngData - END -->
				*/

				if (dpcheng.TagWznmJobList) {
					var tcos = [];

					/*
					*/
					tcos.push({value: "jnum", text: "jnum"}, {value: "TcoSrf", text: this.tag.TcoSrf}, {value: "TcoTyp", text: this.tag.TcoTyp}, {value: "TcoVer", text: this.tag.TcoVer}, {value: "TcoRet", text: this.tag.TcoRet}, {value: "TcoReu", text: this.tag.TcoReu}, {value: "TcoGbl", text: this.tag.TcoGbl}, {value: "TcoCls", text: this.tag.TcoCls}, {value: "TcoShd", text: this.tag.TcoShd});
					/*
					*/

					this.contapp.tcos = tcos;
				}

				if (dpcheng.ListWznmQJobList) {
					var rows = [];

					for (var i = 0; i < this.rst.length; i++) {
						var rec = this.rst[i];
						/*
						*/
						rows.push({jnum: rec["jnum"], TcoSrf: rec["srf"], TcoTyp: rec["typ2"], TcoVer: rec["ver"], TcoRet: rec["ret2"], TcoReu: rec["reu"], TcoGbl: rec["gbl"], TcoCls: rec["cls"], TcoShd: rec["shd"]})
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
				if (srefIxWznmVDpch == "DpchEngWznmJobListData") this.mergeDpchEngData(dpcheng);
			},

			/*
			*/
			/*
			*/

			handleUpdate: function(obj) {
				/*
				*/
				if (obj.srefIxWznmVDpch == "DpchEngWznmJobListData") this.mergeDpchEngData(obj.dpcheng);
				/*
				*/
			}
		},

		computed: {
			/*
			*/
			Cpt2: function() {
				if (this.statshr.srefIxWznmVExpstate == "mind") return(" (" + this.statshrqry.ntot + ")");
				return "";
			},

			TxtFor: function() {
				return(" " + Wznm.strFor(this.tag.TxtFor, this.continf.TxtFor) + " ");
			},
			/*
			*/
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
